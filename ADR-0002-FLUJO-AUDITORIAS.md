---
author: "Milton / Copilot"
date: "2026-05-21"
hash: "sha256:f804e72e88dbf675968d259f50f57284d198ed0dea6c09f90cf11b55f3bc7067"
ia_source: "Gemini PRO"
status: "validated"
title: "ADR-0002: Flujo de Auditorías"
version: "0.1"

---

## Contexto

Centinela del Monte requiere un proceso de auditoría claro, repetible y auditable para todas las decisiones críticas, cambios de arquitectura, entregables y releases. Las auditorías deben garantizar que los artefactos generados sean verificables, que el flujo de trabajo sea transparente y que las responsabilidades estén separadas.

## Decisión

Se define un flujo de auditoría estándar que se integra con la gobernanza ya establecida en la doctrina:

1. Generar
   - Todo cambio crítico comienza en `/staging`.
   - Los artefactos deben incluir metadatos YAML con `title`, `author`, `ia_source`, `version`, `date`, `status` y `hash`.
2. Staging
   - Revisar internamente la propuesta técnica y la metadata.
   - Registrar las evidencias de revisión en `/auditorias`.
   - Verificar que el hash y la firma de documento sean válidos.
3. Validar
   - Revisión por al menos una persona humana.

## Consecuencias
- Garantiza trazabilidad total de los artefactos antes de su promoción a release.
