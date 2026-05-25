---
author: "Gemini PRO"
date: "2026-05-21"
hash: "sha256:997a684ae82466f6beb0487f4ddb6297a77eb2405b886218f9ac59a9b6e1e329"
ia_source: "Gemini PRO"
status: "validated"
title: "ADR-0006: Gobernanza y DOCTRINA.md"
version: "0.1"

---

## Contexto
El proyecto Centinela del Monte requiere trazabilidad completa y un flujo de trabajo estricto para el manejo de cambios críticos.

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
