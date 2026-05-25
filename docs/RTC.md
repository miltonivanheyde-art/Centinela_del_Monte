---
title: "Especificaciones Detalladas de Reloj de Tiempo Real (RTC)"
author: "Gemini PRO"
reviewed_by: "Milton Heyde"
ia_source: "Gemini Code Assist"
status: "validated"
version: "v0.1"
date: "2026-05-21"
hash: "sha256:988a7802cbdaba93e1df9d22db03ae11c4c78ff1b5753fe06ac81c8bcd400cdf"

---


# Especificaciones Detalladas de Reloj de Tiempo Real (RTC)

## 1. Componente RTC (Ref: ADR-0001-FATIGA-TERMICA)
- **Tipo:** RTC externo con cristal de cuarzo compensado por temperatura (TCXO).
- **Interfaz:** I2C o SPI.
- **Precisión:** ±2 ppm (partes por millón) en el rango de -40°C a +85°C.
- **Batería de Respaldo:** Supercapacitor o batería de botón para mantener la hora durante cortes de energía.
- **Funcionalidad:** Alarma programable para despertar el MCU del Deep Sleep.
