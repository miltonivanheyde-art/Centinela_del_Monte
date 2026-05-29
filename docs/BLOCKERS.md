---
title: "Registro de Bloqueadores (Blockers)"
author: "Gemini PRO"
hash: "sha256:1548ebcbfdf56cc95c18dc3b01cbb649946ded0afb7fb0f1cf297a47e9a10315"
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


