---
author: "Gemini PRO"
date: "2026-05-21"
hash: "sha256:b1c2d3e4f5a6b7c8d9e0f1a2b3c4d5e6f7a8b9c0d1e2f3a4b5c6d7e8f9a0b1c2"
ia_source: "Gemini Code Assist"
reviewed_by: "Milton Heyde"
status: "validated"
title: "Protocolo de Heartbeat"
version: "v0.1"
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

## Notas Técnicas
Cualquier ajuste de frecuencia debe registrarse mediante ADR si impacta la autonomía de 6 meses definida en la doctrina.