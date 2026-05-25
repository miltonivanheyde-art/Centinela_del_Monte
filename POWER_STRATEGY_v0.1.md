---
title: "Estrategia de Gestión de Potencia"
version: "v0.1"
status: "validated"
author: "Gemini PRO"
ia_source: "Gemini Code Assist"
reviewed_by: "Milton Heyde"
date: "2026-05-21"
hash: "sha256:35ee24640c96a837c62934c2bd0374d40e2a4a729f4961cc1f31d29bc27f8d99"

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
