---
author: "Gemini PRO"
date: "2026-05-21"
hash: "sha256:14711fcc7ee615838054ecc2ac3dca7f8011a95f6889ee7a3486f184410f3b84"
reviewed_by: "Milton Heyde"
status: "validated"
title: "ADR-TERMICA: Umbrales de Seguridad"
version: "v0.1"

---


# ADR-TERMICA: Control de Temperatura

## Contexto
El hardware está expuesto a variaciones térmicas extremas en el monte.

## Decisión
Establecer el punto de apagado de seguridad (Estado BLACK) en 60°C internos para proteger el SoC y la batería.

## Consecuencias
Prevención de daños permanentes, aunque el nodo pueda quedar fuera de servicio durante picos de calor extremo.
