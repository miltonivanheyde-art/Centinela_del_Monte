---
title: "Especificaciones Detalladas de Reloj de Tiempo Real (RTC)"
author: "Gemini PRO"
reviewed_by: "Milton Heyde"
ia_source: "Gemini Code Assist"
status: "validated"
version: "v0.1"
date: "2026-05-21"
hash: "sha256:3511ea29b68f6e70ba632fbe51fa8e3ca08cd07a6f637fb031b2f12ae242514c"


---



# Especificaciones Detalladas de Reloj de Tiempo Real (RTC)

## 1. Componente RTC (Ref: ADR-0001-FATIGA-TERMICA)
- **Tipo:** RTC externo con cristal de cuarzo compensado por temperatura (TCXO).
- **Interfaz:** I2C o SPI.
- **Precisión:** ±2 ppm (partes por millón) en el rango de -40°C a +85°C.
- **Batería de Respaldo:** Supercapacitor o batería de botón para mantener la hora durante cortes de energía.
- **Funcionalidad:** Alarma programable para despertar el MCU del Deep Sleep.

