---
author: "Gemini PRO"
date: "2026-05-21"
ia_source: "Gemini Code Assist"
reviewed_by: "Milton Heyde"
status: "draft"
title: "Estrategia de Gestión Energética"
version: "v0.1"
---

# Política Energética Centinela

## Umbrales de Operación
- **Normal:** > 70% (Estado PRESENTE).
- **Ahorro:** 30% - 70% (Reducción de muestreo de sensores).
- **Reserva:** < 15% (Solo Heartbeat mínimo cada 8 horas).
- **Crítico:** < 5% (Apagado de seguridad / Estado BLACK).

## Modos de Ahorro
- Uso de Deep Sleep forzado entre transmisiones.
- Desactivación de reguladores de sensores I2C/SPI mediante MOSFET de corte.

## Comportamiento por Estado
- **En RESERVA:** El nodo ignora peticiones de datos no esenciales.
- **En ALERTA:** Se prioriza la transmisión del evento aunque comprometa el umbral de reserva.

## Resiliencia
El sistema MPPT solar debe priorizar la recuperación del estado **RESERVA** a **PRESENTE** antes de reanudar logs de alta frecuencia.