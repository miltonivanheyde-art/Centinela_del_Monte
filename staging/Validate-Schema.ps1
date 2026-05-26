<#
.SYNOPSIS
    Valida que todos los archivos Markdown y código fuente (.c, .h) en las capas técnicas
    cumplan con el esquema de metadatos YAML obligatorio definido en la DOCTRINA.
#>

# Configuración de rutas y campos obligatorios
$basePath = "h:\OneDrive\Archivos de Microsoft Copilot Chat\CENTINELA_DEL_MONTE"
$technicalLayers = @(".", "hardware")
$mandatoryFields = @("title", "author", "ia_source", "version", "date", "hash", "status")

Write-Host "--- Auditoría de Gobernanza: Verificación de Esquema YAML ---" -ForegroundColor Cyan
Write-Host "Objetivo: Asegurar integridad estructural en capas técnicas." -ForegroundColor Gray

$globalSuccess = $true
$failedFiles = @()

foreach ($layer in $technicalLayers) {
    $fullPath = Join-Path $basePath $layer
    if (-not (Test-Path $fullPath)) {
