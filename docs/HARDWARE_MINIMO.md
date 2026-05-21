---
title: "Especificaciones de Hardware Mínimo (Resumen)"
author: "Gemini PRO"
reviewed_by: "Milton Heyde"
ia_source: "Gemini Code Assist"
status: "validated"
version: "v0.1"
date: "2026-05-21"
hash: "sha256:c9d8e7f6a5b4c3d2e1f0a9b8c7d6e5f4a3b2c1d0e9f8a7b6c5d4e3f2a1b0c9d8"
---

## Especificaciones de Hardware Mínimo - Proyecto Centinela del Monte

## 1. Unidad de Procesamiento y Control

- **MCU:** Microcontrolador de ultra bajo consumo con soporte para Deep Sleep (ej. ESP32-S3 o similar).
- **Memoria:** Mínimo 8MB PSRAM para buffers de sensores y logs locales.
- **Reloj:** RTC externo de alta precisión con compensación de temperatura (TCXO). (Ref: ADR-0001-FATIGA-TERMICA)

## 2. Subsistema de Energía (Ref: ADR-ENERGIA)

- **Batería:** Celda LiFePO4 (Lithium Iron Phosphate) - Mínimo 3000mAh.
- **Regulación:** LDO con corriente de reposo (Iq) inferior a 1µA.
- **Carga:** Controlador de carga solar MPPT integrado para panel de 5V/10W.
- **Monitoreo:** Divisor de tensión de alta impedancia para lectura de VBat.

## 3. Sensores y Actuadores (Ref: ESPECIFICACIONES_SENSORES.md)

- **Temperatura/Humedad:** Sensor digital (I2C) con rango operativo de -40°C a +85°C.
- **Movimiento:** Acelerómetro/Giroscopio para detección de actividad y sabotaje.
- **Integridad:** Switch de sabotaje (Tamper) para detección de apertura de gabinete.

## 4. Comunicaciones (Ref: ADR-HEARTBEAT, ESPECIFICACIONES_COMUNICACIONES.md)

- **Radio:** Módulo LoRaWAN o enlace satelital de bajo consumo.
- **Antena:** Externa, protegida contra UV y condiciones climáticas extremas.

## 5. Parámetros Operativos (Ref: ADR-TERMICA, ESPECIFICACIONES_MECANICAS.md)

- **Umbral de Seguridad:** Apagado automático (Estado BLACK) al alcanzar los 60°C internos.
- **Gabinete:** Grado de protección IP67, material con tratamiento UV y disipación pasiva.

## 6. Referencias Detalladas

- `specs/ENERGIA.md`
- `specs/COMUNICACIONES.md`
- `specs/MECANICAS.md`
- `specs/SENSORES.md`
- `specs/RTC.md`
