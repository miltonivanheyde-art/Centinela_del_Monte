---
title: "Especificaciones Detalladas de Reloj de Tiempo Real (RTC)"
author: "Gemini PRO"
reviewed_by: "Milton Heyde"
ia_source: "Gemini Code Assist"
status: "validated"
version: "v0.1"
date: "2026-05-21"
hash: "sha256:d9e0f1a2b3c4d5e6f7a8b9c0d1e2f3a4b5c6d7e8f9a0b1c2d3e4f5a6b7c8d9e0"
---

# Especificaciones Detalladas de Reloj de Tiempo Real (RTC)

## 1. Componente RTC (Ref: ADR-0001-FATIGA-TERMICA)
- **Tipo:** RTC externo con cristal de cuarzo compensado por temperatura (TCXO).
- **Interfaz:** I2C o SPI.
- **Precisión:** ±2 ppm (partes por millón) en el rango de -40°C a +85°C.
- **Batería de Respaldo:** Supercapacitor o batería de botón para mantener la hora durante cortes de energía.
- **Funcionalidad:** Alarma programable para despertar el MCU del Deep Sleep.