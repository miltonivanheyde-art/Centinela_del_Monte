#!/bin/sh
# Centinela del Monte - Git Pre-Commit Hook
# Ensures metadata and hashes are updated before the commit is finalized.

echo "Centinela Core: Updating document metadata and SHA256 hashes..."

# Run the PowerShell script
powershell.exe -ExecutionPolicy Bypass -File ./scripts/Update-DocumentMetadata.ps1

echo "Centinela Core: Running integrity validation..."
powershell.exe -ExecutionPolicy Bypass -File ./scripts/Validate-Artifact.ps1

if [ $? -ne 0 ]; then
    echo "CRITICAL: Integrity validation failed. Commit aborted."
    exit 1
fi

# Stage the changes made by the script so they are included in the current commit
git add -u