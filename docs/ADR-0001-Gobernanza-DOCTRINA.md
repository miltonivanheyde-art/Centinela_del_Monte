---
author: "Copilot"
date: "2026-05-21"
hash: "sha256:e8f9a0b1c2d3e4f5a6b7c8d9e0f1a2b3c4d5e6f7a8b9c0d1e2f3a4b5c6d7e8f9"
ia_source: "Copilot"
status: "validated"
title: "ADR 0001: Arquitectura de gobernanza doctrinal"
version: "0.2"
---

## ADR 0001: Arquitectura de gobernanza doctrinal

## Contexto

Centinela del Monte define una arquitectura cognitiva donde diferentes sistemas de IA tienen roles separados:

- **Gemini PRO** es la autoridad doctrinal y debe validar las decisiones clave.
- **ChatGPT** es el generador técnico y trabaja principalmente en `/staging`.
- **Copilot 365** es responsable de persistencia, backups y sincronización.

El proyecto exige trazabilidad completa, auditorías continuas y un flujo de trabajo estricto para el manejo de cambios.

## Decisión

Adoptar un modelo de gobernanza que implemente estas reglas clave:

1. Separar roles doctrinales, técnicos y de persistencia.
2. Aplicar el flujo obligatorio: `generar → staging → validar → release`.
3. Requerir ADRs con metadatos completos (`ID`, `autor`, `ia_source`, `versión`, `hash`, `fecha`, `status`).
4. Usar hashes SHA-256 y timestamps ISO8601 para asegurar integridad e historial.
5. Establecer la validación doctrinal de Gemini PRO como requisito obligatorio y vinculante para todos los cambios en `/releases` y la aprobación de nuevas ADRs.

## Consecuencias

- Todo cambio crítico quedará documentado con un ADR firmado.
- Se elimina la ambigüedad en la promoción de artefactos: ningún elemento llegará a `/releases` sin la verificación de coherencia doctrinal de Gemini PRO.
