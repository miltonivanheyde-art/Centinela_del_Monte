---
author: "Gemini PRO"
date: "2026-05-21"
hash: "sha256:a2b3c4d5e6f7a8b9c0d1e2f3a4b5c6d7e8f9a0b1c2d3e4f5a6b7c8d9e0f1a2b3"
ia_source: "Gemini Code Assist"
reviewed_by: "Milton Heyde"
status: "validated"
title: "Lógica de Estados Doctrinales"
version: "v0.1"
---

# Estados Doctrinales del Nodo

## Estados Oficiales
- **PRESENTE:** Operación nominal, latido constante.
- **ACTIVO:** Detección de evento o telemetría de alta frecuencia.
- **RESERVA:** Consumo mínimo, funciones críticas limitadas.
- **ALERTA:** Anomalía detectada, reporte inmediato de interrupción.
- **SIN_CONTACTO:** Ventana de transmisión fallida.
- **RECUPERADO:** Retorno a operación tras fallo o mantenimiento.

## Variables Mínimas de Control
- **Temperatura:** Monitoreo del SoC y ambiente.
- **Batería:** Porcentaje de carga y voltaje (LiFePO4).
- **Movimiento:** Datos de aceleración para detección de sabotaje.
- **Tiempo sin transmisión:** Temporizador desde el último ACK.

## Reglas de Transición
1. **Temperatura > Umbral Crítico (60°C):** Transición automática a **RESERVA** para enfriamiento pasivo.
2. **Batería Crítica (< 15%):** Transición a **RESERVA**; desactivación de periféricos.
3. **Sin Heartbeat (> 125% intervalo):** El orquestador marca el estado como **SIN_CONTACTO**.
4. **Detección de Movimiento:** Si el nodo está en reposo, transición inmediata a **ACTIVO**.

## Validación Doctrinal
Este esquema cumple con el principio de "Resiliencia de Campo" (Doctrina v0.2).