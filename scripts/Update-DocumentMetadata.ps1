param(
    [Parameter(Mandatory=$true)]
    [string]$Path,

    [string]$Title,
    [string]$Author = "Copilot",
    [string]$IaSource = "Copilot",
    [string]$Version = "0.1",
    [ValidateSet("draft", "release")]
    [string]$Status = "draft"
)

if (-not (Test-Path $Path)) {
    throw "El archivo especificado no existe: $Path"
}

$absolutePath = Resolve-Path $Path
$content = Get-Content -Raw -Path $absolutePath
$lines = $content -split "`r?`n"

$hasFrontMatter = $false
$headerEndIndex = -1
if ($lines.Count -gt 0 -and $lines[0].Trim() -eq '---') {
    for ($i = 1; $i -lt $lines.Count; $i++) {
        if ($lines[$i].Trim() -eq '---') {
            $headerEndIndex = $i
            $hasFrontMatter = $true
            break
        }
    }
}

if ($hasFrontMatter) {
    $yamlLines = $lines[1..($headerEndIndex - 1)]
    $bodyLines = if ($headerEndIndex + 1 -lt $lines.Count) { $lines[($headerEndIndex + 1)..($lines.Count - 1)] } else { @() }
} else {
    $yamlLines = @()
    $bodyLines = $lines
}

$meta = @{}
foreach ($line in $yamlLines) {
    if ($line -match '^(?<key>[^:]+)\s*:\s*(?<value>.*)$') {
        $meta[$matches['key'].Trim()] = $matches['value'].Trim(' "')
    }
}

if (-not $Title) {
    if ($meta.ContainsKey('title') -and $meta['title']) {
        $Title = $meta['title']
    } else {
        $Title = [System.IO.Path]::GetFileNameWithoutExtension($absolutePath)
    }
}

$meta['title'] = $Title
$meta['author'] = $Author
$meta['ia_source'] = $IaSource
$meta['version'] = $Version
$meta['date'] = (Get-Date).ToString('yyyy-MM-dd')
$meta['status'] = $Status
$meta['hash'] = ""

function Write-YamlHeader($metadata) {
    $header = @('---')
    foreach ($key in $metadata.Keys | Sort-Object) {
        $value = $metadata[$key]
        if ($value -ne '') {
            $header += "$key: \"$value\""
        }
    }
    $header += '---'
    return $header
}

$yamlHeader = Write-YamlHeader $meta
$hashPayload = ($yamlHeader + $bodyLines) -join "`r`n"
$hashBytes = [System.Text.Encoding]::UTF8.GetBytes($hashPayload)
$sha256 = [System.BitConverter]::ToString((New-Object System.Security.Cryptography.SHA256Managed).ComputeHash($hashBytes)).Replace('-','').ToLowerInvariant()
$meta['hash'] = "sha256:$sha256"

$yamlHeader = Write-YamlHeader $meta
$result = ($yamlHeader + $bodyLines) -join "`r`n"
Set-Content -Path $absolutePath -Value $result -Encoding UTF8
Write-Host "Metadata updated for '$Path' with hash $sha256."
