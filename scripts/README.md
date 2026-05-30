---
title: "Manual de Scripts de Automatización e Integridad"
author: "Gemini Code Assist"
ia_source: "Gemini Code Assist"
version: "v1.1"
date: "2026-05-21"
status: "validated"
hash: "sha256:93043c220e0d94a783c46be54e0936d711bcc22bb3896860915d81d213e81e89"
---

# Scripts de Automatización — Centinela del Monte

Este directorio contiene herramientas para garantizar la **integridad estructural** y la **trazabilidad de los artefactos documentales** del repositorio `CENTINELA_DEL_MONTE`.

Estos scripts son fundamentales para el cumplimiento de los principios de:

- **Integridad sobre velocidad**
- **Trazabilidad documental**
- **Consistencia semántica**

Aplican a todos los documentos del repositorio, incluyendo:

- Documentación técnica (`/docs`)
- Capa investor-ready (`/docs/pitch`)

---

## 1. Update-DocumentMetadata.ps1

### Propósito

Este script actúa como mecanismo de **verificación de integridad documental**.

Calcula el hash SHA256 del contenido de los archivos Markdown (excluyendo el bloque YAML) y actualiza automáticamente el campo `hash` en los metadatos.

---

### Uso

Debe ejecutarse cada vez que se modifique el contenido de un archivo `.md`, antes de realizar un commit.

```powershell
.\scripts\Update-DocumentMetadata.ps1