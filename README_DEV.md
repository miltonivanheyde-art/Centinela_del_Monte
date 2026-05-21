# 🧠 Guía de Desarrollo – Proyecto Centinela del Monte

## 1. Propósito
Este documento orienta la configuración del entorno de desarrollo local con **VS Code**, **GitHub Copilot Chat** y la sincronización con **OneDrive**.

## 2. Requisitos previos
- Visual Studio Code instalado.
- Extensiones:
  - GitHub Copilot
  - GitHub Copilot Chat
  - Markdown Preview Enhanced
  - GitLens
- Cuenta de GitHub autenticada.
- Carpeta local sincronizada con OneDrive (`CENTINELA_DEL_MONTE`).

## 3. Apertura del proyecto
1. Abrir VS Code → *Archivo → Abrir carpeta* → seleccionar `CENTINELA_DEL_MONTE`.
2. Confirmar que los archivos doctrinales y técnicos se muestran en el explorador.

## 4. Configuración recomendada
Crear `.vscode/settings.json` con:
```json
{
  "editor.formatOnSave": true,
  "git.enableSmartCommit": true,
  "markdown.preview.breaks": true,
  "copilot.enable": true,
  "copilot.chat.enable": true
}
```

## 5. Documentación del workflow
- El flujo operativo obligatorio está descrito en `WORKFLOW.md`.
- Todas las decisiones críticas deben registrarse mediante ADRs en `docs/`.
- El proceso de auditoría está definido en `docs/ADR-0002.md`.

- Nueva ADR: `docs/ADR-0003.md` introduce la validación automática de metadatos y firma antes de promover artefactos a `/releases`.

## 6. Backups y resiliencia
- El script de respaldo del proyecto se encuentra en `scripts/Backup-CENTINELA.ps1`.
- Use `powershell ./scripts/Backup-CENTINELA.ps1 -Compress` para crear copias comprimidas.
- Ajuste `-BackupRoot` si desea guardar copias en otra carpeta de OneDrive.
