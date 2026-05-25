---
title: "Máquina de Estados del Nodo (FSM)"
version: "v0.1"
status: "validated"
author: "Gemini PRO"
ia_source: "Gemini Code Assist"
date: "2026-05-20"
hash: "sha256:52f0e1bd8ec33f17c6ac89cc910bede49a32b6d3d360057c597feb34b7059168"

---


## Definición de Estados

| Estado | Acción Principal | Condición de Salida |
| :--- | :--- | :--- |
| **INIT** | Configuración de GPIOs y Buses | Automático tras Power-on |
| **SLEEP** | Deep Sleep (MCU + Sensores Off) | Alarma RTC o Interrupción Tamper |
| **SENSE** | Power On Periféricos + Lectura | Lectura Completada |
| **TX** | Transmisión LoRa (SX1262) | Paquete enviado o Timeout |
| **CRITICAL** | Registro de error en Flash | Reset manual o watchdog |

## Lógica de Despertar
El sistema utiliza el pin **GPIO 15** conectado al pin `SQW/INT` del DS3231 para despertar cada N minutos según la configuración doctrinal.

## Gestión de Energía en FSM
1. Al entrar en **SLEEP**, el pin `GPIO 3` debe forzarse a `LOW`.
2. Al entrar en **SENSE**, el pin `GPIO 3` pasa a `HIGH`, seguido de un `delay(50)` para estabilización de tensión.
