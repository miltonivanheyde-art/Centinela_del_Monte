---
title: "Índice de Decisiones de Arquitectura (ADRs)"
version: "v0.1"
status: "validated"
author: "Gemini Code Assist"
ia_source: "Gemini PRO"
date: "2026-05-21"
hash: "sha256:5ae1c3a928b4a723209ec8068a0441ce7f0b236f58303833308275b6fe351ab5"


---


## Propósito

Este documento sirve como índice centralizado para todas las Decisiones de Arquitectura (ADRs) del proyecto Centinela del Monte, facilitando la navegación y comprensión de las decisiones clave que rigen el sistema.

## Índice de ADRs

| ID | Título | Estado | Impacto Clave | Dependencias |
| :--- | :--- | :--- | :--- | :--- |
| ADR-0001 | Mitigación de Fatiga Térmica en Sensores I2C | Validado | Resiliencia, Consumo | `firmware/docs/PINOUT_v0.1.md` |
| ADR-0002 | Flujo de Auditorías | Validado | Gobernanza, Trazabilidad | `docs/DOCTRINA.md` |
| ADR-0003 | Validación automática de metadata y firma de artefactos antes de release | Validado | Automatización, Integridad | `scripts/Validate-Schema.ps1` |
| ADR-0005 | Actualización de DOCTRINA.md a versión v0.2 | Validado | Gobernanza, Coherencia | `docs/DOCTRINA.md` |
| ADR-0006 | Gobernanza y DOCTRINA.md | Validado | Roles, Flujo | `docs/DOCTRINA.md` |
| ADR-0007 | Unificación de Intervalo de Heartbeat | Validado | Consumo, Comunicación | `docs/HEARTBEAT_v0.1.md` |

## Cómo Usar este Índice

- Para entender una decisión específica, consulte el archivo ADR correspondiente en esta misma carpeta.
- Las dependencias indican otros documentos o ADRs relevantes para la comprensión completa de la decisión.

