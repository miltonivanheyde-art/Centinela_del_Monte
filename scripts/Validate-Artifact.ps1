param(
    [Parameter(Mandatory=$true)]
    [string]$Path
)

# Leer contenido del archivo
$content = Get-Content $Path -Raw

# Extraer bloque YAML
$yaml = ($content -split '---')[1]

# Calcular hash real
$bytes = [System.Text.Encoding]::UTF8.GetBytes($content)
$sha256 = [System.Security.Cryptography.SHA256]::Create()
$hash = ($sha256.ComputeHash($bytes) | ForEach-Object { $_.ToString("x2") }) -join ""

# Validar coincidencia
if ($yaml -match "sha256:$hash") {
    $status = "✅ Hash válido"
} else {
    $status = "❌ Hash inconsistente"
}

# Registrar auditoría
$report = @"
# Auditoría de Validación — $(Get-Date -Format 'yyyy-MM-dd')
Archivo: $Path
Resultado: $status
Hash calculado: $hash
"@
$outdir = "auditorias"
if (-not (Test-Path $outdir)) { New-Item -Path $outdir -ItemType Directory | Out-Null }
$report | Out-File "$outdir/VALIDACION-$(Get-Date -Format 'yyyy-MM-dd').md" -Encoding UTF8
Write-Host $status
Write-Host "Reporte escrito en: $outdir/VALIDACION-$(Get-Date -Format 'yyyy-MM-dd').md"
