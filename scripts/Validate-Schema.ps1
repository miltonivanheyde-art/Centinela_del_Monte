<#
.SYNOPSIS
    Valida que todos los archivos Markdown en las capas técnicas (/firmware y /hardware)
    cumplan con el esquema de metadatos YAML obligatorio definido en la DOCTRINA.
#>

# Configuración de rutas y campos obligatorios
$basePath = "h:\OneDrive\Archivos de Microsoft Copilot Chat\CENTINELA_DEL_MONTE"
$technicalLayers = @("firmware", "hardware")
$mandatoryFields = @("title", "author", "ia_source", "version", "date", "hash", "status")

Write-Host "--- Auditoría de Gobernanza: Verificación de Esquema YAML ---" -ForegroundColor Cyan
Write-Host "Objetivo: Asegurar integridad estructural en capas técnicas." -ForegroundColor Gray

$globalSuccess = $true
$failedFiles = @()

foreach ($layer in $technicalLayers) {
    $fullPath = Join-Path $basePath $layer
    if (-not (Test-Path $fullPath)) {
        Write-Host "  [!] Directorio /$layer no encontrado. Omitiendo." -ForegroundColor Yellow
        continue
    }

    $files = Get-ChildItem -Path $fullPath -Filter "*.md" -File -Recurse
    Write-Host "`nEscaneando: /$layer ($($files.Count) archivos)" -ForegroundColor Yellow

    foreach ($file in $files) {
        $content = Get-Content -Path $file.FullName -Raw
        $missing = @()

        # Extraer el bloque YAML entre delimitadores '---' al inicio del archivo
        if ($content -match "(?s)^---\r?\n(.*?)\r?\n---") {
            $yamlHeader = $Matches[1]
            foreach ($field in $mandatoryFields) {
                # Verificar existencia de la clave al inicio de línea (usando regex multilínea)
                if ($yamlHeader -notmatch "(?m)^$field\s*:") {
                    $missing += $field
                }
            }
        }
        else {
            $missing += "BLOQUE YAML FRONTAL (Ausente o mal formado)"
        }

        if ($missing.Count -eq 0) {
            Write-Host "  [OK]   $($file.Name)" -ForegroundColor Green
        }
        else {
            Write-Host "  [FAIL] $($file.Name) - Faltan campos: $($missing -join ', ')" -ForegroundColor Red
            $globalSuccess = $false
            $failedFiles += [PSCustomObject]@{
                Name    = $file.Name
                Path    = $file.FullName
                Missing = $missing -join ", "
            }
        }
    }
}

# Generación de reporte en /auditorias
$auditDir = Join-Path $basePath "auditorias"
if (-not (Test-Path $auditDir)) { New-Item -Path $auditDir -ItemType Directory | Out-Null }

$reportPath = Join-Path $auditDir "SCHEMA-VALIDATION-$((Get-Date).ToString('yyyy-MM-dd')).md"
$reportContent = "# Reporte de Validación de Esquema YAML — $((Get-Date).ToString('yyyy-MM-dd'))`n`n"

if ($failedFiles.Count -eq 0) {
    $reportContent += "✅ Todos los archivos en /firmware y /hardware cumplen con el esquema obligatorio.`n"
}
else {
    $reportContent += "❌ Se detectaron fallos en los siguientes archivos:`n`n"
    $reportContent += "| Archivo | Campos Faltantes | Ruta |`n| :--- | :--- | :--- |`n"
    foreach ($fail in $failedFiles) {
        $reportContent += "| $($fail.Name) | $($fail.Missing) | $($fail.Path) |`n"
    }
}

$reportContent | Out-File -FilePath $reportPath -Encoding UTF8
Write-Host "`nReporte generado en: $reportPath" -ForegroundColor Gray

Write-Host "`n--- Informe Final de Esquema ---" -ForegroundColor Cyan
if ($globalSuccess) {
    Write-Host "CUMPLIMIENTO: 100%. Las capas técnicas son determinísticas." -ForegroundColor Green
}
else {
    Write-Host "CUMPLIMIENTO: Incompleto. Se requieren correcciones manuales." -ForegroundColor Red
    exit 1
}