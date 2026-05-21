param(
    [string]$Path = "h:\OneDrive\Archivos de Microsoft Copilot Chat\CENTINELA_DEL_MONTE",
    [string]$Remote = "origin",
    [string]$Branch = "main"
)

# Función para limpieza de OneDrive
function Clean-OneDriveTempFiles ($repoPath) {
    $tempPatterns = @("* (conflicted copy)*", "~$*", "*.tmp")
    foreach ($pattern in $tempPatterns) {
        Get-ChildItem -Path $repoPath -Recurse -Include $pattern -ErrorAction SilentlyContinue | Remove-Item -Force -ErrorAction SilentlyContinue
    }
}

$Watcher = New-Object System.IO.FileSystemWatcher
$Watcher.Path = $Path
$Watcher.Filter = "*.md"
$Watcher.IncludeSubdirectories = $true
$Watcher.EnableRaisingEvents = $true

Write-Host "🚀 Centinela Sync activado en $Path" -ForegroundColor Cyan

$Action = {
    $FilePath = $Event.SourceEventArgs.FullPath
    $FileName = $Event.SourceEventArgs.Name
    
    if ($FilePath -match "(\.git|auditorias|node_modules)") { return }

    try {
        Clean-OneDriveTempFiles $Path
        Set-Location $Path
        
        # 1. Fetch y verificación de estado Git
        git fetch $Remote $Branch -q
        if (Test-Path "$Path\.git\rebase-merge" -or Test-Path "$Path\.git\rebase-apply") {
            throw "Rebase incompleto detectado."
        }

        # 2. Actualizar Metadata
        & "$Path\scripts\Update-DocumentMetadata.ps1" -Path $FilePath
        
        # 3. Validar
        $validationOutput = & "$Path\scripts\Validate-Artifact.ps1" -Path $FilePath | Out-String
        if ($validationOutput -match "❌") {
            # Bloque Debug en caso de fallo
            $raw = Get-Content -Raw -Path $FilePath
            Write-Host "⚠️ Fallo de validación en $FileName. Revisando integridad..." -ForegroundColor Red
            throw "Fallo de validación doctrinal."
        }

        # 4. Git Push solo si hay cambios reales
        git add $FilePath
        $status = git status --porcelain $FilePath
        if ($null -ne $status -and $status -ne "") {
            git commit -m "Auto-sync: $FileName"
            git pull --rebase $Remote $Branch
            git push $Remote $Branch
            
            # 5. Log de éxito
            $currentBranch = (git rev-parse --abbrev-ref HEAD).Trim()
            $currentHash = if ($validationOutput -match "Hash Calculado: (?<hash>[a-f0-9]+)") { $Matches['hash'] } else { "N/A" }
            $syncAuditLog = Join-Path $Path "auditorias\SYNC-$((Get-Date).ToString('yyyy-MM-dd')).md"
            
            $logEntry = "`n## [$((Get-Date).ToString('HH:mm:ss'))] Sincronización Exitosa`n`n" +
                        "- **Archivo:** $FileName`n" +
                        "- **Rama:** ``$currentBranch`` `n" +
                        "- **Hash:** ``sha256:$currentHash`` `n" +
                        "- **Resultado:** ✅ Metadata, Validación e Integración con Remoto completadas.`n"
            
            Add-Content -Path $syncAuditLog -Value $logEntry -Encoding UTF8
            Write-Host "✅ Sincronizado: $FileName" -ForegroundColor Green
        } else {
            Write-Host "ℹ️ Sin cambios pendientes para $FileName" -ForegroundColor Gray
        }
    }
    catch {
        Write-Error "❌ Error en sincronización: $_"
        Add-Type -AssemblyName System.Windows.Forms
        $notif = New-Object System.Windows.Forms.NotifyIcon
        $notif.Icon = [System.Drawing.SystemIcons]::Error
        $notif.Visible = $true
        $notif.ShowBalloonTip(5000, "Centinela Sync Error", $_.Exception.Message, [System.Windows.Forms.ToolTipIcon]::Error)
    }
}

Register-ObjectEvent $Watcher "Changed" -Action $Action

while ($true) { Start-Sleep -Seconds 5 }
