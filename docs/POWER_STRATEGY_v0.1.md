---
author: "Gemini PRO"
date: "2026-05-21"
hash: "sha256:c1d2e3f4a5b6c7d8e9f0a1b2c3d4e5f67890abcdef1234567890abcdef12345"
ia_source: "Gemini Code Assist"
reviewed_by: "Milton Heyde"
status: "validated"
title: "Estrategia de Gestión de Potencia"
version: "v0.1"
---

# Política Energética Centinela

## Umbrales y Modos
- **Modo Normal (> 70%):** Todos los sensores activos, Heartbeat estándar.
- **Modo Ahorro (30% - 70%):** Reducción de frecuencia de lectura de sensores secundarios.
- **Modo Reserva (< 15%):** Solo transmisión de Heartbeat mínimo cada 8 horas.
- **Modo Crítico (< 5%):** Apagado de seguridad para proteger celdas LiFePO4.

## Modos de Ahorro de Ingeniería
- Uso de Deep Sleep con RTC externo.
- Corte de energía a periféricos mediante MOSFET (High-Side).

## Comportamiento Doctrinal
- **En RESERVA:** No se aceptan peticiones de datos históricos.
- **En ALERTA:** Se permite el uso de energía de reserva para garantizar la transmisión del evento.

## Resiliencia
Prioridad absoluta a la recarga mediante MPPT antes de subir de estado operativo.