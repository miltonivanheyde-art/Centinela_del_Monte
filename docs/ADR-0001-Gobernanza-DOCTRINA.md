---
title: "ADR 0001: Arquitectura de gobernanza doctrinal"
author: "Copilot"
ia_source: "Copilot"
version: "0.1"
date: "2026-05-21"
hash: "sha256:<placeholder>"
status: "draft"
---

# ADR 0001: Arquitectura de gobernanza doctrinal

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
5. Exigir aprobaciones humanas para cambios en `/releases` y registrar validaciones doctrinales.

## Consecuencias
- Todo cambio crítico quedará documentado con un ADR firmado.
- La separación de responsabilidades reducirá ambigüedad y mejorará el cumplimiento.
- El proceso de despliegue será más lento, pero más seguro y auditable.
- Las revisiones futuras podrán rastrear decisiones y artefactos con metadatos YAML y auditorías.

## Alternativas consideradas
- Permitir que una sola IA controlara todos los pasos: rechazado por falta de segregación de funciones.
- No usar hashes ni metadatos estructurados: rechazado por pérdida de trazabilidad.

## Implementación propuesta
- Crear un repositorio de ADRs en `docs/` o `auditorias/`.
- Validar cada ADR con al menos una aprobación humana y, cuando sea crítico, la validación de Gemini PRO.
- Registrar versiones exactas de las IAs utilizadas en cada ADR.
