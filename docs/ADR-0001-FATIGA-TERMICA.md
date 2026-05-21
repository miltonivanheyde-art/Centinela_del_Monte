---
author: "Gemini PRO"
date: "2026-05-21"
hash: "sha256:c0d1e2f3a4b5c6d7e8f9a0b1c2d3e4f5a6b7c8d9e0f1a2b3c4d5e6f7a8b9c0d1"
ia_source: "Gemini Code Assist"
reviewed_by: "Milton Heyde"
status: "validated"
title: "ADR-0001: Gestión de Fatiga Térmica en Componentes Críticos"
version: "v0.1"
---
## ADR-0001: Gestión de Fatiga Térmica en Componentes Críticos

## Problema

Las oscilaciones térmicas extremas del monte (día/noche) afectan la estabilidad de los cristales de cuarzo en el RTC y degradan físicamente las uniones de soldadura.

## Decisión

1. Implementar una política de "Sueño Gradual": el nodo no sella el Deep Sleep si la temperatura interna supera los 45°C.
2. Uso obligatorio de cristales TCXO (Temperature Compensated Crystal Oscillator).
3. Gabinetes con disipación pasiva y tratamiento UV.

## Consecuencias

- **Positivas:** Estabilidad del Heartbeat y mayor vida útil del hardware.
- **Negativas:** Incremento en el costo de la lista de materiales (BOM).

## Validación Doctrinal

Cumple con la Doctrina Fundacional v0.2: La resiliencia física es prioritaria para la trazabilidad de largo plazo.

## Validación Técnica Mínima

Pruebas de ciclo térmico en cámara ambiental (60°C a -5°C) con monitoreo de drift de reloj.
