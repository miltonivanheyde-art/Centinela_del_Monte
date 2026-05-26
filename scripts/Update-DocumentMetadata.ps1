# Script: Update-DocumentMetadata.ps1

Write-Host "=== Actualizando hashes SHA256 ===" -ForegroundColor Cyan

# Obtener archivos Markdown y código fuente (C/H)
$files = Get-ChildItem -Recurse -Include *.md, *.c, *.h

foreach ($file in $files) {
    $path = $file.FullName

    # Leer contenido
    $content = Get-Content -Path $path -Raw -Encoding UTF8

    # Procesar Archivos Markdown (YAML Frontmatter)
    if ($file.Extension -eq ".md" -and $content -match "(?s)^---(.*?)---") {

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
    # Procesar Archivos de Código (Tags @hash en comentarios)
    elseif ($file.Extension -match "\.(c|h)$") {
        if ($content -match "(?m)@hash\s+(sha256:[a-f0-9]{64}|sha256:pending_hash)") {
            
            # Para el hash, excluimos la línea que contiene el tag @hash para evitar circularidad
            $body = $content -replace "(?m)^.*@hash\s+sha256:.*$", ""
            
            # Calcular hash
            $bytes = [System.Text.Encoding]::UTF8.GetBytes($body)
            $sha256 = [System.Security.Cryptography.SHA256]::Create().ComputeHash($bytes)
            $hashString = -join ($sha256 | ForEach-Object { "{0:x2}" -f $_ })

            # Reemplazar tag @hash
            $newContent = $content -replace "@hash\s+(sha256:[a-f0-9]{64}|sha256:pending_hash)", "@hash sha256:$hashString"
            
            Set-Content -Path $path -Value $newContent -Encoding UTF8
            Write-Host "✔ $($file.Name) (C/H) hash actualizado" -ForegroundColor Green
        }
    }
    else {
        Write-Host "⚠ $($file.Name) omitido (sin metadatos detectados)" -ForegroundColor Yellow
    }
}

Write-Host "=== Finalizado ===" -ForegroundColor Cyan
