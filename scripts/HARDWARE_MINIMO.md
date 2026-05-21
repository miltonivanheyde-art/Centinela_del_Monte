---
author: "Gemini PRO"
date: "2026-05-21"
hash: "sha256:4f8b9d3e6a7c2b5f1e0d9a8c7b6a5f4e3d2c1b0a9f8e7d6c5b4a3f2e1d0c9b8a"
ia_source: "Gemini Code Assist"
reviewed_by: "Milton Heyde"
status: "draft"
title: "Especificaciones de Hardware Mínimo"
version: "v0.1"
---

# Especificaciones de Hardware Mínimo - Proyecto Centinela del Monte

## 1. Unidad de Procesamiento y Control
- **MCU:** Microcontrolador de ultra bajo consumo con soporte para Deep Sleep (ej. ESP32-S3 o similar).
- **Memoria:** Mínimo 8MB PSRAM para buffers de sensores y logs locales.
- **Reloj:** RTC externo de alta precisión para gestión de Heartbeat independiente del SoC.

## 2. Subsistema de Energía (Ref: ADR-ENERGIA)
- **Batería:** Celda LiFePO4 (Lithium Iron Phosphate) - Mínimo 3000mAh.
- **Regulación:** LDO con corriente de reposo (Iq) inferior a 1µA.
- **Carga:** Controlador de carga solar MPPT integrado para panel de 5V/10W.
- **Monitoreo:** Divisor de tensión de alta impedancia para lectura de VBat sin fugas de corriente.

## 3. Sensores y Actuadores
- **Temperatura/Humedad:** Sensor digital (I2C) con rango operativo de -40°C a +85°C.
- **Integridad:** Switch de sabotaje (Tamper) para detección de apertura de gabinete (Estado BLACK).

## 4. Comunicaciones (Ref: ADR-HEARTBEAT)
- **Radio:** Módulo LoRaWAN o enlace satelital de bajo consumo.
- **Antena:** Externa, protegida contra rayos UV y condiciones climáticas extremas.

## 5. Parámetros Operativos (Ref: ADR-TERMICA)
- **Umbral de Seguridad:** Apagado automático (Estado BLACK) al alcanzar los 60°C internos.
- **Gabinete:** Grado de protección IP67, material con tratamiento UV y disipación pasiva.

## 6. Requerimiento de Validación
> **NOTA DOCTRINAL:** Este documento requiere la validación de coherencia técnica y cumplimiento de ADRs por parte de **Gemini PRO** para transicionar de `draft` a `validated`.

### Pendientes de Definición
- [ ] Selección final del transceptor de radio.
- [ ] Esquema de patillaje (Pinout) para sensores I2C.