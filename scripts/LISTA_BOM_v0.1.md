---
author: "Gemini Code Assist"
date: "2026-05-21"
hash: "sha256:a1b2c3d4e5f67890abcdef1234567890abcdef1234567890abcdef1234567890"
ia_source: "Gemini Code Assist"
reviewed_by: "Milton Heyde"
status: "validated"
title: "Lista de Materiales (BOM) - Prototipo v0.1"
version: "v0.1"
---

## Lista de Materiales (BOM) - Prototipo v0.1

## 1. Procesamiento y Tiempo Real

- **MCU:** ESP32-S3-WROOM-1-N8R8 (8MB Flash, 8MB PSRAM). Soporta Deep Sleep y optimización de energía.
- **RTC (TCXO):** DS3231SN. Reloj de tiempo real con cristal compensado por temperatura integrado (precisión ±2ppm de -40°C a +85°C). Cumple con el **ADR-0001**.

## 2. Gestión de Energía

- **Batería:** Celda LiFePO4 3.2V 3000mAh (Química estable para ciclos térmicos extremos).
- **Regulador LDO:** TPS7A0233 (Corriente de reposo ultra baja de 25nA).
- **Cargador Solar:** CN3163 (Controlador de carga para LiFePO4 con capacidad de entrada solar).
- **Panel Solar:** Celda monocristalina 5V/10W con recubrimiento ETFE para protección UV.

## 3. Sensores

- **Temperatura/Humedad:** Sensirion SHT31-DIS-B (I2C, alta precisión, sellado contra contaminantes).
- **IMU (Detección de Movimiento):** ADXL345 (Acelerómetro de 3 ejes con interrupciones por actividad).
- **Seguridad (Tamper)::** Micro-switch mecánico tipo SPDT con palanca larga.

## 4. Comunicaciones

- **LoRa:** Módulo Semtech SX1262 (Ej. Ebyte E22-900M22S). Mayor eficiencia que la serie SX127x.
- **Antena:** Antena omnidireccional 915MHz, ganancia 3dBi, IP67.

## 5. Gabinete y Estructura

- **Caja:** Gabinete de policarbonato IP67 con protección UV (aprox. 120x80x50mm).
- **Prensaestopas:** Conectores IP68 para salida de antena y cable solar.

## 6. Notas de Ensamblaje

Se recomienda el uso de soldadura sin plomo con aleación SAC305 para mitigar la fatiga mecánica por ciclos térmicos mencionada en el **ADR-0001**.