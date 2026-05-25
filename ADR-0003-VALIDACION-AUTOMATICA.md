---
author: "Milton / Copilot"
date: "2026-05-21"
hash: "sha256:6e5a23b33d4c2a045f8299a2b75af2c7ad53f0970d989159beed50f1b1d0ea48"
ia_source: "ChatGPT"
status: "validated"
title: "ADR-0003: Validación automática de metadata y firma de artefactos antes de release"
version: "0.1"

---

## Contexto
El proyecto exige que todos los artefactos que lleguen a `/releases` incluyan metadatos YAML completos y un hash SHA-256 verificable. Actualmente la verificación es mayormente manual, lo que puede inducir errores humanos y demoras en el flujo `generar → staging → validar → release`.

## Decisión
Adoptar un paso obligatorio de validación automática en la etapa de `staging` que:

- Verifique la presencia y el esquema mínimo de metadatos YAML (`title`, `author`, `ia_source`, `version`, `date`, `hash`, `status`).
- Calcule y compare el hash SHA-256 del contenido con el campo `hash` del YAML.
- Genere un informe de validación en `/auditorias/<artifact>-validation-<date>.yaml` con resultado `pass|fail` y metadatos de verificación.
- Bloquee la promoción automática a `/releases` si la validación falla; exponga información de falla para corrección en `staging`.

La validación podrá implementarse como:
- Un script PowerShell integrado (`scripts/Validate-Artifact.ps1`) que use `scripts/Update-DocumentMetadata.ps1` y herramientas de hash existentes.
- Un hook de CI/CD (opcional) que ejecute la validación en pushes a ramas de staging.

## Consecuencias
- Reducción de errores humanos en la validación de integridad y metadatos.
