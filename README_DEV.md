---
author: "Copilot"
date: "2026-05-21"
hash: "sha256:6d7e8f9a0b1c2d3e4f5a6b7c8d9e0f1a2b3c4d5e6f7a8b9c0d1e2f3a4b5c6d7e"
ia_source: "Copilot"
status: "draft"
title: "README_DEV"
version: "0.1"
---

## 🧠 Guía de Desarrollo – Proyecto Centinela del Monte

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
