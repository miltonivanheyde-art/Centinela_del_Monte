# 2. Calcular integridad con la fecha existente para detectar cambios reales
$testHeader = Write-YamlHeader $meta
$testPayload = ($testHeader + $bodyLines) -join "`n" # Normalización a LF para consistencia de Hash
$testBytes = [System.Text.Encoding]::UTF8.GetBytes($testPayload)
$currentContentSignature = "sha256:" + [System.BitConverter]::ToString(([System.Security.Cryptography.SHA256]::Create()).ComputeHash($testBytes)).Replace('-', '').ToLowerInvariant()

# 3. Si el hash coincide con el almacenado, no hubo cambios doctrinales. Omitimos actualización.
if ($currentContentSignature -eq $storedHash) {
    Write-Host "✅ No se detectaron cambios en el contenido ni metadata de '$Path'. Omitiendo actualización de fecha."
    return
}

# 4. Si hay cambios, actualizamos la fecha y recalculamos el hash final
$meta['date'] = (Get-Date).ToString('yyyy-MM-dd')
$meta['hash'] = "" # El hash siempre se recalcula

$yamlHeader = Write-YamlHeader $meta
$hashPayload = ($yamlHeader + $bodyLines) -join "`n" # Normalización a LF para consistencia de Hash
$hashBytes = [System.Text.Encoding]::UTF8.GetBytes($hashPayload)
$sha256 = [System.BitConverter]::ToString(([System.Security.Cryptography.SHA256]::Create()).ComputeHash($hashBytes)).Replace('-', '').ToLowerInvariant()
$meta['hash'] = "sha256:$sha256"

$yamlHeader = Write-YamlHeader $meta
$result = ($yamlHeader + $bodyLines) -join "`r`n"
Set-Content -Path $absolutePath -Value $result -Encoding UTF8
Write-Host "Metadata updated for '$Path' with hash $sha256."
