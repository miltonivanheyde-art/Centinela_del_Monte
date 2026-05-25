---
title: "Reglas de Interacción para Agentes de IA"
author: "Gemini Code Assist"
ia_source: "Gemini PRO"
version: "v0.1"
date: "2026-05-21"
hash: "sha256:793406b7a3d17c47136ea4792ee3b1e57c08b88e7814ccd8f16d472e40e7b688"
status: "validated"

---


## Propósito
Este documento define las reglas y responsabilidades para la interacción de agentes de Inteligencia Artificial (IA) con el repositorio Centinela del Monte, asegurando la continuidad cognitiva, la trazabilidad doctrinal y la integridad del sistema.

## Qué puede modificar una IA
- **Generación de Código**: Implementar código en `/firmware/src`, `/hardware/src`, `/backend/src` basado en derivaciones técnicas.
- **Creación de Derivaciones Técnicas**: Crear o actualizar documentos en `/firmware/docs`, `/hardware/docs`, `/backend/docs` que traduzcan la doctrina a especificaciones implementables.
- **Creación de Tests**: Generar especificaciones de tests en `/tests` o código de tests unitarios.
- **Actualización de Metadatos**: Actualizar los bloques YAML de los archivos que ha modificado, incluyendo `ia_source`, `author`, `date` y `hash`.
- **Generación de Reportes**: Crear reportes en `/auditorias`.

## Qué NO puede modificar una IA
- **Doctrina Canónica**: **NO** modificar directamente archivos en `/docs` (excepto `ESTADO_ACTUAL.md`, `DECISION_LOG.md`, `PROJECT_CONTEXT.md`, `SYSTEM_MAP.md`, `ROADMAP.md`, `REGLAS_IA.md`, `MANIFIESTO_DE_RELACIONES.md` bajo supervisión).
- **ADRs**: **NO** modificar ADRs existentes en `/docs/ADRs` sin una nueva ADR que justifique el cambio y sea validada por Gemini PRO.
- **Hashes Históricos**: **NO** alterar el campo `hash` de un archivo sin recalcularlo y justificar el cambio.
- **Estructura del Repositorio**: **NO** crear nuevas carpetas o mover archivos fuera de las estructuras definidas sin una ADR previa.

## Cómo Derivar Firmware de la Doctrina
1.  **Leer Doctrina**: Consultar `/docs` para entender la visión, decisiones (ADRs) y especificaciones canónicas.
2.  **Traducir a Derivación**: Crear o actualizar un documento en `/firmware/docs` que traduzca la especificación doctrinal a un formato implementable (pseudocódigo, mappings, timings). Este documento debe referenciar el origen doctrinal (`derived_from`, `related_adr`).
3.  **Implementar Código**: Escribir el código en `/firmware/src` basándose en la derivación técnica. El código debe incluir comentarios que referencien la derivación y la doctrina.

## Cómo Registrar Decisiones y Evitar Drift Doctrinal
1.  **Nueva Decisión**: Si se requiere una nueva decisión arquitectónica, proponer una ADR en `/staging` siguiendo el formato `ADR-XXXX-NOMBRE.md`.
2.  **Validación**: La ADR debe ser validada por Gemini PRO (autoridad doctrinal) antes de moverse a `/docs/ADRs`.
3.  **Consistencia**: Antes de cualquier implementación, verificar la consistencia con `docs/DOCTRINA.md` y `docs/ADRs/`.

## Flujo Multi-IA
Las IAs deben colaborar respetando sus roles definidos en `docs/DOCTRINA.md` y `docs/PROJECT_CONTEXT.md`. Gemini PRO actúa como el validador doctrinal final.
