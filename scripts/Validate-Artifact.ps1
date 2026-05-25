param(
    [Parameter(Mandatory = $true)]
    [string]$Path
)

# Leer contenido del archivo
$content = Get-Content -Path $Path -Raw

# Extraer el hash almacenado en los metadatos usando regex
if ($content -match 'hash:\s*"sha256:(?<val>[a-f0-9]+)"') {
    $storedHash = $Matches['val']
}
else {
    $storedHash = $null
}

# Normalización Doctrinal: Para evitar la dependencia circular, reemplazamos el valor 
# del hash por una cadena vacía ("") antes de calcular la integridad. 
# Esto replica la carga útil usada en scripts/Update-DocumentMetadata.ps1.
$contentForValidation = $content -replace 'hash:\s*"sha256:[a-f0-9]*"', 'hash: ""'

# Calcular hash real
$bytes = [System.Text.Encoding]::UTF8.GetBytes($contentForValidation)
$sha256 = New-Object System.Security.Cryptography.SHA256Managed
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
