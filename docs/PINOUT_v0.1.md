---
author: "Gemini PRO"
date: "2026-05-21"
hash: "sha256:7d8e9f0a1b2c3d4e5f6a7b8c9d0e1f2a3b4c5d6e7f8a9b0c1d2e3f4a5b6c7d8e"
ia_source: "Gemini Code Assist"
reviewed_by: "Milton Heyde"
status: "validated"
title: "Asignación de Pines (Pinout) - Prototipo v0.1"
version: "v0.1"
---

## Asignación de Pines (Pinout) - ESP32-S3

## 1. Bus I2C (Sensores y RTC)

Se utiliza un único bus I2C para periféricos de baja velocidad. Se requiere Pull-up externo de 4.7kΩ a la línea de alimentación protegida.

| Periférico | Pin SDA | Pin SCL | Dirección I2C | Notas |
| :--- | :--- | :--- | :--- | :--- |
| **DS3231 (RTC)** | GPIO 4 | GPIO 5 | 0x68 | Reloj TCXO (ADR-0001) |
| **SHT31 (Temp/Hum)** | GPIO 4 | GPIO 5 | 0x44 | Sensor principal |
| **ADXL345 (IMU)** | GPIO 4 | GPIO 5 | 0x53 | Detección de movimiento |

## 2. Bus SPI (Comunicaciones LoRa)

Asignado al bus FSPI del ESP32-S3 para máxima compatibilidad con el módulo SX1262.

| Función LoRa | Pin ESP32-S3 | Tipo | Notas |
| :--- | :--- | :--- | :--- |
| **SCK** | GPIO 12 | Salida | Reloj SPI |
| **MISO** | GPIO 13 | Entrada | Datos desde LoRa |
| **MOSI** | GPIO 11 | Salida | Datos hacia LoRa |
| **NSS (CS)** | GPIO 10 | Salida | Chip Select |
| **BUSY** | GPIO 14 | Entrada | Estado del transceptor |
| **DIO1** | GPIO 21 | Entrada | Interrupción de eventos LoRa |
| **RESET** | GPIO 47 | Salida | Reset físico del módulo |

## 3. Entradas Digitales y Analógicas

| Función | Pin | Tipo | Notas |
| :--- | :--- | :--- | :--- |
| **Tamper Switch** | GPIO 1 | Entrada (Pull-up) | Detección de apertura (Wake-up capaz) |
| **VBat Monitor** | GPIO 2 | ADC1_CH1 | Divisor resistivo (100k/100k) |
| **RTC SQW/INT** | GPIO 15 | Entrada | Interrupción por alarma de tiempo |

## 4. Control de Energía

| Función | Pin | Tipo | Notas |
| :--- | :--- | :--- | :--- |
| **Power Enable** | GPIO 3 | Salida | Control MOSFET (Corte de sensores) |

## 5. Notas de Implementación

- Los pines GPIO 1, 2 y 15 se seleccionaron por ser capaces de despertar al MCU desde el modo *Deep Sleep*.
- El pin **Power Enable** debe estar en nivel BAJO durante el sueño profundo para garantizar que los sensores no consuman energía.
