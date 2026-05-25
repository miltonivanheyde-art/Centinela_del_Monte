---
author: "Copilot"
date: "2026-05-21"
hash: "sha256:629fbcff3b423b35812f40a8ea475368ef238987887ec098794af6ae9a09e10d"
ia_source: "Copilot"
status: "draft"
title: "WORKFLOW"
version: "0.1"

---


## 2. Flujo obligatorio

1. **Generar**
   - Crear artefactos y ADRs en `/staging`.
   - Incluir metadatos YAML obligatorios.
   - Aplicar formato y preparar el contenido para revisión.

2. **Staging**
   - Revisar la propuesta internamente.
   - Verificar que los metadatos incluyan hash y versión de IA.
   - Registrar evidencia en `/auditorias` si corresponde.

3. **Validar**
   - Validación humana mínima de un revisor.
   - **Obligatorio:** Validación doctrinal por Gemini PRO para TODA decisión de arquitectura (ADR) o cambio en `/releases`.
   - El estado metadata debe cambiar de `draft` a `validated`.

4. **Release**
   - Solo mover artefactos a `/releases` después de la validación.
   - Actualizar el registro de auditoría con el resultado final.
   - Asegurar que el estado metadata sea `release`.

## 3. Auditorías

- El flujo de auditorías es un proceso paralelo y obligatorio.
- Documentar cada auditoría en `/auditorias` con:
  - Fecha
  - Responsable
  - Alcance
  - Resultado
  - Referencia a ADRs y artefactos

