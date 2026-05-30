Write-Host "VALIDATION GATE - CENTINELA DEL MONTE" -ForegroundColor Cyan

# Definición de rutas relativas al script
$repoRoot = Split-Path -Parent $PSScriptRoot

try {
    # 1. Estructura prohibida
    $forbiddenDirs = @("staging", "auditorias")
    foreach ($dir in $forbiddenDirs) {
        if (Test-Path (Join-Path $repoRoot $dir)) {
            throw "Forbidden directory detected: $dir"
        }
    }

    # 2. Estructura mínima esperada
    $mandatoryDirs = @("docs", "main", "scripts")
    foreach ($dir in $mandatoryDirs) {
        if (-not (Test-Path (Join-Path $repoRoot $dir))) {
            throw "Mandatory directory missing: $dir"
        }
    }

    # 3. Estado Git limpio
    # Nota: Se asume que el script se ejecuta en un entorno donde git está disponible
    $gitStatus = git status --porcelain
    if ($gitStatus) {
        Write-Host "Current Git Status:" -ForegroundColor Gray
        $gitStatus | ForEach-Object { Write-Host "  $_" -ForegroundColor Yellow }
        throw "Repository is not clean (git status is not empty)"
    }

    # 4. Archivos huérfanos críticos
    # Permitimos archivos de configuración esenciales de ESP-IDF y del proyecto en la raíz
    $allowedFiles = @("CMakeLists.txt", "sdkconfig", ".gitignore", "README.md", "partitions.csv", "LICENSE")
    $rootFiles = Get-ChildItem -Path $repoRoot -File
    foreach ($file in $rootFiles) {
        if ($allowedFiles -notcontains $file.Name) {
            throw "Critical orphan file detected in root: $($file.Name)"
        }
    }
}
catch {
    # Captura cualquier error lanzado por 'throw' o por el sistema
    $reason = $_.Exception.Message
    if (-not $reason) { $reason = $_ }
    
    Write-Host "❌ FAIL: $reason" -ForegroundColor Red
    exit 1
}

# 5. Output de éxito
if ($null -eq $Error[0] -or $Error.Count -eq 0) {
    Write-Host "✔ PASS: repository valid" -ForegroundColor Green
    exit 0
}
# 5. Output de éxito
if ($LastExitCode -eq 0 -or $null -eq $LastExitCode) {
    Write-Host "✔ PASS: repository valid" -ForegroundColor Green
    exit 0
}