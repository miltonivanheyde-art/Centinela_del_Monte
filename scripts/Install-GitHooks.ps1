<#
.SYNOPSIS
    Installs project Git hooks by copying them from /scripts to /.git/hooks.
#>

$repoRoot = Get-Location
$hookSource = Join-Path $repoRoot "scripts\git-pre-commit.sh"
$hookTarget = Join-Path $repoRoot ".git\hooks\pre-commit"

if (Test-Path ".git") {
    Write-Host "Installing Centinela Git Hooks..." -ForegroundColor Cyan
    Copy-Item -Path $hookSource -Destination $hookTarget -Force
    Write-Host "SUCCESS: Pre-commit hook installed at $hookTarget" -ForegroundColor Green
}
else {
    Write-Error "Not a git repository root. Please run this from the project root."
}