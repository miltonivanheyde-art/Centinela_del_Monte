param(
    [Parameter(Mandatory = $true)]
    [string]$Path
)

# Leer contenido del archivo
$content = Get-Content -Raw -Path $Path
$lines = $content -split "`r?`n"

# Identificar Front Matter
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

if (-not $hasFrontMatter) { throw "El archivo no contiene metadatos YAML válidos." }

$yamlLines = $lines[1..($headerEndIndex - 1)]
$bodyLines = if ($headerEndIndex + 1 -lt $lines.Count) { $lines[($headerEndIndex + 1)..($lines.Count - 1)] } else { @() }

# Parsear metadatos para obtener el hash y preparar la base de firma
$meta = @{}
foreach ($line in $yamlLines) {
    if ($line -match '^(?<key>[^:]+)\s*:\s*(?<value>.*)$') {
        $meta[$Matches['key'].Trim()] = $Matches['value'].Trim(' "')
    }
}

$storedHash = if ($meta.ContainsKey('hash')) { $meta['hash'].Replace('sha256:', '') } else { $null }
$meta['hash'] = "" # Signature Base

# Reconstrucción idéntica a Update-DocumentMetadata.ps1
function Get-SignatureBase($metadata, $body) {
    $header = @('---')
    foreach ($key in $metadata.Keys | Sort-Object) {
        if ($null -ne $metadata[$key]) {
            $header += $key + ': "' + $metadata[$key] + '"'
        }
    }
    $header += '---'
    return ($header + $body) -join "`r`n"
}

$contentForValidation = Get-SignatureBase $meta $bodyLines

# Calcular hash real
$bytes = [System.Text.Encoding]::UTF8.GetBytes($contentForValidation)
$sha256 = [System.Security.Cryptography.SHA256]::Create()
$calculatedHash = [System.BitConverter]::ToString($sha256.ComputeHash($bytes)).Replace('-', '').ToLowerInvariant()

# Validar coincidencia
if ($storedHash -eq $calculatedHash) {
    $status = "✅ Hash válido"
}
else {
    $status = "❌ Hash inconsistente"
}

# Registrar auditoría
$report = @"
# Auditoría de Validación — $(Get-Date -Format 'yyyy-MM-dd')
Archivo: $Path
Resultado: $status
Hash calculado: $calculatedHash
"@
$outdir = "auditorias"
if (-not (Test-Path $outdir)) { New-Item -Path $outdir -ItemType Directory | Out-Null }
$report | Out-File "$outdir/VALIDACION-$(Get-Date -Format 'yyyy-MM-dd').md" -Encoding UTF8
Write-Host $status
Write-Host "Hash Calculado: $calculatedHash"
Write-Host "Reporte escrito en: $outdir/VALIDACION-$(Get-Date -Format 'yyyy-MM-dd').md"
