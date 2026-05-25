# Script: Update-DocumentMetadata.ps1

Write-Host "=== Actualizando hashes SHA256 ===" -ForegroundColor Cyan

# Obtener todos los archivos markdown
$files = Get-ChildItem -Recurse -Filter *.md

foreach ($file in $files) {
    $path = $file.FullName

    # Leer contenido
    $content = Get-Content -Path $path -Raw

    # Detectar YAML
    if ($content -match "(?s)^---(.*?)---") {

        $yamlBlock = $matches[1]
        $body = $content -replace "(?s)^---.*?---", ""
        # Calcular hash del body
        $bytes = [System.Text.Encoding]::UTF8.GetBytes($body)
        $sha256 = [System.Security.Cryptography.SHA256]::Create().ComputeHash($bytes)
        $hashString = -join ($sha256 | ForEach-Object { "{0:x2}" -f $_ })

        # Reemplazar hash en YAML
        $newYaml = $yamlBlock -replace 'hash:\s*".*?"', "hash: `"sha256:$hashString`""

        # Reconstruir archivo
        $newContent = "---$newYaml`n---`n$body"
        Set-Content -Path $path -Value $newContent -Encoding UTF8

        Write-Host "✔ $($file.Name) actualizado" -ForegroundColor Green
    }
    else {
        Write-Host "⚠ $($file.Name) sin YAML" -ForegroundColor Yellow
    }
}

Write-Host "=== Finalizado ===" -ForegroundColor Cyan

