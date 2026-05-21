---
title: "Registro de Bloqueadores (Blockers)"
author: "Gemini PRO"
hash: "sha256:8d9e0f1a2b3c4d5e6f7a8b9c0d1e2f3a4b5c6d7e8f9a0b1c2d3e4f5a6b7c8d9e"
reviewed_by: "Milton Heyde"
status: "validated"
version: "v0.1"
date: "2026-05-21"
---

## Bloqueadores y Riesgos

## Técnicos

- **Hash Mismatch:** Riesgo de desincronización manual de hashes en documentos markdown durante ediciones rápidas. *Mitigación: Uso obligatorio de scripts/Update-DocumentMetadata.ps1.*
- **Fatiga Térmica:** La oscilación térmica extrema puede degradar la precisión del RTC (Reloj de tiempo real).
- **Integridad de Firmware:** Necesidad de definir el proceso de firmado de binarios.

## Operacionales

- **Validación Humana:** Disponibilidad de revisores para la transición de `staging` a `release` según ADR-0002.
- **Hardware:** Selección final de componentes críticos y proveedores para el cálculo de autonomía energética.
