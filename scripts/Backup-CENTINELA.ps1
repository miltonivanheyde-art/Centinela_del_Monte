param(
    [Parameter(Mandatory=$false)]
    [string]$SourcePath = "$(Get-Location)",

    [Parameter(Mandatory=$false)]
    [string]$BackupRoot = "$env:USERPROFILE\OneDrive\Backups\CENTINELA_DEL_MONTE",

    [Parameter(Mandatory=$false)]
    [switch]$Compress,

    [Parameter(Mandatory=$false)]
    [string[]]$Exclude = @('*.tmp','*.log','*.vs','node_modules','bin','obj')
)

function Write-ErrorAndExit($message) {
    Write-Host "ERROR: $message" -ForegroundColor Red
    exit 1
}

if (-not (Test-Path $SourcePath)) {
    Write-ErrorAndExit "La ruta de origen no existe: $SourcePath"
}

$sourceFullPath = Resolve-Path $SourcePath
$timestamp = Get-Date -Format 'yyyyMMdd_HHmmss'
$backupDir = Join-Path $BackupRoot $timestamp

Write-Host "Origen: $sourceFullPath"
Write-Host "Destino de backup: $backupDir"

if (-not (Test-Path $BackupRoot)) {
    New-Item -Path $BackupRoot -ItemType Directory -Force | Out-Null
}

New-Item -Path $backupDir -ItemType Directory -Force | Out-Null

$excludePatterns = @()
foreach ($pattern in $Exclude) {
    if ($pattern.Trim()) {
        $excludePatterns += $pattern
    }
}

$items = Get-ChildItem -Path $sourceFullPath -Force
foreach ($item in $items) {
    $destination = Join-Path $backupDir $item.Name
    $isExcluded = $false
    foreach ($pattern in $excludePatterns) {
        if ($item.Name -like $pattern) {
            $isExcluded = $true
            break
        }
    }
    if ($isExcluded) {
        Write-Host "Excluyendo: $($item.Name)"
        continue
    }
    try {
        if ($item.PSIsContainer) {
            Copy-Item -Path $item.FullName -Destination $destination -Recurse -Force -ErrorAction Stop
        } else {
            Copy-Item -Path $item.FullName -Destination $destination -Force -ErrorAction Stop
        }
    } catch {
        Write-Warning "No se pudo copiar $($item.FullName): $_"
    }
}

if ($Compress) {
    $zipPath = Join-Path $BackupRoot "CENTINELA_DEL_MONTE_Backup_$timestamp.zip"
    if (Test-Path $zipPath) { Remove-Item $zipPath -Force }
    Compress-Archive -Path (Join-Path $backupDir '*') -DestinationPath $zipPath -Force
    Write-Host "Backup comprimido creado en: $zipPath"
}

Write-Host "Backup completado en: $backupDir" -ForegroundColor Green
Write-Host "Archivos excluidos: $($Exclude -join ', ')"
