# 1. Calcular Hash SHA256 del cuerpo (Body)
$sha256 = [System.Security.Cryptography.SHA256Managed]::new()
$bytes = [System.Text.Encoding]::UTF8.GetBytes($body)
$hashBytes = $sha256.ComputeHash($bytes)
$calculatedHash = "sha256:$(([System.BitConverter]::ToString($hashBytes) -replace '-').ToLower())"

# 2. Extraer Hash Registrado
$registeredHash = "none"

# Detectar hash según formato (YAML key o @hash tag)
if ($yamlBlock -match "(?m)^[\s\*]*hash:\s*\"?(sha256:[a-f0-9] { 64 })\"?") {
    $registeredHash = $Matches[1]
}
elseif ($yamlBlock -match "@hash\s+(sha256:[a-f0-9]{64})") {
    $registeredHash = $Matches[1]
}

$status = "FAIL"
if ($calculatedHash -eq $registeredHash) {
    $status = "PASS"
    Write-Host "  [PASS] $($file.Name)" -ForegroundColor Green
}
else {
    $globalSuccess = $false
    Write-Host "  [FAIL] $($file.Name) - Hash Mismatch" -ForegroundColor Red
}

$results += [PSCustomObject]@{
    Archivo    = $file.Name
    Estado     = $status
    Registrado = $registeredHash
    Calculado  = $calculatedHash
}
}
else {
    Write-Host "  [SKIP] $($file.Name) - Sin bloque YAML doctrinal" -ForegroundColor Yellow
}
}

# Generar Reporte de Auditoría
$reportHeader = @"
---
title: "Reporte de Validación de Integridad"
author: "Gemini Code Assist"
version: "v1.0"