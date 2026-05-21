---
author: "Gemini PRO"
date: "2026-05-21"
hash: "sha256:b3e4d5f6a7b8c9d0e1f2a3b4c5d6e7f8a9b0c1d2e3f4a5b6c7d8e9f0a1b2c3d4"
ia_source: "Gemini Code Assist"
status: "draft"
title: "Protocolo de Heartbeat (Latido de Red)"
version: "0.1"
---
# Protocolo de Heartbeat (Latido de Red)

## Ciclo de Vida del Mensaje
1. **Frecuencia de despertar:** Cada 2 horas (Unificado por ADR-0006).
2. **Ventana de escucha:** 30 segundos tras despertar para recibir comandos de sincronización.
3. **Momento de transmisión:** T+35 segundos; envío de payload de estado.
4. **Momento de sleep:** Inmediatamente tras confirmación de recepción (ACK) o timeout de 60s.

## Métricas Estimadas
- **Consumo estimado:** 25mA durante transmisión (LoRaWAN/Sat), < 10µA en Deep Sleep.
- **Payload enviado:** `[NODE_ID, BATT_LVL, TEMP_INTERNAL, STATE_CODE, TIMESTAMP]`.

## Gobernanza
Cualquier cambio en la frecuencia de despertar debe ser precedido por una actualización del ROADMAP y validación de impacto energético.