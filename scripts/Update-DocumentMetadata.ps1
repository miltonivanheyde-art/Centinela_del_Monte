param(
    [Parameter(Mandatory = $true)]
    [string]$Path,

    [string]$Title,
    [string]$Author, # Eliminamos el valor predeterminado para que el script pueda tomar el valor existente del archivo
    [string]$IaSource, # Eliminamos el valor predeterminado
    [string]$Version, # Eliminamos el valor predeterminado
    [ValidateSet("draft", "release")]
    [string]$Status # Eliminamos el valor predeterminado
)

if (-not (Test-Path $Path)) {
    throw "El archivo especificado no existe: $Path"
}

$absolutePath = Resolve-Path $Path
$content = Get-Content -Raw -Path $absolutePath
$lines = $content -split "`r?`n"

$hasFrontMatter = $false
$headerEndIndex = -1
if ($lines.Count -gt 0 -and $lines[0].Trim() -eq '---') {
    for ($i = 1; $i -lt $lines.Count; $i++) {
        if ($lines[$i].Trim() -eq '---') {
            $headerEndIndex = $i
            $hasFrontMatter = $true
            break
        }
    }
}

if ($hasFrontMatter) {
    $yamlLines = $lines[1..($headerEndIndex - 1)]
    $bodyLines = if ($headerEndIndex + 1 -lt $lines.Count) { $lines[($headerEndIndex + 1)..($lines.Count - 1)] } else { @() }
}
else {
    $yamlLines = @()
    $bodyLines = $lines
}

$meta = @{}
foreach ($line in $yamlLines) {
    if ($line -match '^(?<key>[^:]+)\s*:\s*(?<value>.*)$') {
        $meta[$Matches['key'].Trim()] = $Matches['value'].Trim(' "')
    }
}

if (-not $Title) {
    if ($meta.ContainsKey('title') -and $meta['title']) {
        $Title = $meta['title']
    }
    else {
        $Title = [System.IO.Path]::GetFileNameWithoutExtension($absolutePath)
    }
}

# Validación de Autoría Doctrinal
$gitUser = (git config user.name).Trim()
if ($Author -and $gitUser -and $Author -ne $gitUser) {
    Write-Warning "⚠️ El autor proporcionado ($Author) no coincide con el usuario de Git local ($gitUser)."
}

$meta['title'] = if ($Title) { $Title } elseif ($meta.ContainsKey('title')) { $meta['title'] } else { [System.IO.Path]::GetFileNameWithoutExtension($absolutePath) }
$meta['author'] = if ($Author) { $Author } elseif ($meta.ContainsKey('author')) { $meta['author'] } else { "Copilot" } # Usar parámetro, luego valor existente, luego predeterminado
$meta['ia_source'] = if ($IaSource) { $IaSource } elseif ($meta.ContainsKey('ia_source')) { $meta['ia_source'] } else { "Copilot" } # Usar parámetro, luego valor existente, luego predeterminado
$meta['version'] = if ($Version) { $Version } elseif ($meta.ContainsKey('version')) { $meta['version'] } else { "0.1" } # Usar parámetro, luego valor existente, luego predeterminado
$meta['status'] = if ($Status) { $Status } elseif ($meta.ContainsKey('status')) { $meta['status'] } else { "draft" } # Usar parámetro, luego valor existente, luego predeterminado

# 1. Capturar estado previo para validación de cambios
$storedHash = $meta['hash']
$meta['hash'] = "" # Signature Base: El hash se calcula con el campo vacío

function Write-YamlHeader($metadata) {
    $header = @('---')
    foreach ($key in $metadata.Keys | Sort-Object) {
        $value = $metadata[$key]
        # Doctrinal Fix: El campo 'hash' debe incluirse como cadena vacía para el Signature Base
        # para que Validate-Artifact.ps1 pueda replicar el cálculo exactamente.
        if ($null -ne $value -and $key -ne 'hash') {
            $header += $key + ': "' + $value + '"'
        }
        elseif ($key -eq 'hash') {
            $header += 'hash: "' + $value + '"'
        }
    }
    $header += '---'
    return $header
}

# 2. Calcular integridad con la fecha existente para detectar cambios reales
$testHeader = Write-YamlHeader $meta
$testPayload = ($testHeader + $bodyLines) -join "`r`n"
$testBytes = [System.Text.Encoding]::UTF8.GetBytes($testPayload)
$currentContentSignature = "sha256:" + [System.BitConverter]::ToString(([System.Security.Cryptography.SHA256]::Create()).ComputeHash($testBytes)).Replace('-', '').ToLowerInvariant()

# 3. Si el hash coincide con el almacenado, no hubo cambios doctrinales. Omitimos actualización.
if ($currentContentSignature -eq $storedHash) {
    Write-Host "✅ No se detectaron cambios en el contenido ni metadata de '$Path'. Omitiendo actualización de fecha."
    return
}

# 4. Si hay cambios, actualizamos la fecha y recalculamos el hash final
$meta['date'] = (Get-Date).ToString('yyyy-MM-dd')
$meta['hash'] = "" # El hash siempre se recalcula

$yamlHeader = Write-YamlHeader $meta
$hashPayload = ($yamlHeader + $bodyLines) -join "`r`n"
$hashBytes = [System.Text.Encoding]::UTF8.GetBytes($hashPayload)
$sha256 = [System.BitConverter]::ToString(([System.Security.Cryptography.SHA256]::Create()).ComputeHash($hashBytes)).Replace('-', '').ToLowerInvariant()
$meta['hash'] = "sha256:$sha256"

$yamlHeader = Write-YamlHeader $meta
$result = ($yamlHeader + $bodyLines) -join "`r`n"
Set-Content -Path $absolutePath -Value $result -Encoding UTF8
Write-Host "Metadata updated for '$Path' with hash $sha256."
