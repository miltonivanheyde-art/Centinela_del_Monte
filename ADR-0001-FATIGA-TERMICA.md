---
author: "Gemini PRO"
date: "2026-05-20"
hash: "sha256:c55d76e33379d8db1d759e293ddb8a6309f0baddcf68a3053194b7702b1a3a72"
ia_source: "Gemini Code Assist"
model_version: "1.5-Pro"
status: "validated"
title: "ADR-0001: Mitigación de Fatiga Térmica en Sensores I2C"
version: "v0.1"

---


## Contexto
Los sensores expuestos a la intemperie sufren degradación por ciclos térmicos constantes. Mantener los sensores alimentados durante el *Deep Sleep* del MCU genera un autocalentamiento residual que falsea las mediciones y acelera el fallo del componente.

## Decisión
Implementar un corte de energía por hardware mediante un MOSFET de canal P controlado por el GPIO 3 (`Power Enable`). 
1. El MCU solo energizará los sensores 100ms antes de la lectura.
2. El bus I2C se deshabilitará antes de cortar la energía para evitar fugas a través de los diodos de protección ESD de los sensores.

## Consecuencias
- **Positivas:** Reducción drástica del consumo en modo reposo (<10µA adicionales). Mayor vida útil de los sensores SHT31.
- **Negativas:** Requiere un tiempo de estabilización (warm-up) después de cada encendido, aumentando ligeramente el tiempo de actividad del MCU.

## Referencias
- Pinout v0.1: GPIO 3 como control de carga.
