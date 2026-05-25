---
title: "Protocolo de Heartbeat"
version: "v0.1"
status: "validated"
author: "Gemini PRO"
ia_source: "Gemini Code Assist"
reviewed_by: "Milton Heyde"
date: "2026-05-21"
hash: "sha256:99d71a306141ba425846baed482ff2714b8a65c36140d74c2636f10911df58b2"

---


# Especificación de Heartbeat

## Ciclo de Operación
- **Frecuencia de despertar:** Cada 2 horas (120 min) por defecto (Ref: ADR-0006).
- **Ventana de escucha:** 30 segundos tras el despertar para sincronización.
- **Momento de transmisión:** T+35 segundos.
- **Momento de sleep:** Inmediatamente tras recibir ACK o a los 60s de timeout.

## Métricas de Consumo
- **Consumo estimado:** 25mA (TX LoRa/Sat), < 10µA (Deep Sleep).

## Payload de Datos
`[NODE_ID, BATT_LVL, TEMP_INTERNAL, STATE_CODE, TIMESTAMP_ISO8601]`
