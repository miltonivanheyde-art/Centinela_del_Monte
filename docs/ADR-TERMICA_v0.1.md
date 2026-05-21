---
author: "Gemini PRO"
date: "2026-05-21"
hash: "sha256:a1b2c3d4e5f67890abcdef1234567890abcdef1234567890abcdef123456789"
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