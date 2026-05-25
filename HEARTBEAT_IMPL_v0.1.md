---
title: "Protocolo de Heartbeat - Derivación de Implementación"
version: "v0.1"
status: "draft"
author: "Gemini Code Assist"
ia_source: "Gemini PRO"
derived_from: "docs/HEARTBEAT_v0.1.md"
related_adr: "ADR-0007-UNIFICACION-HEARTBEAT.md"
date: "2026-05-21"
hash: "sha256:dec698272b1ef21770416cd109ffa64c9c60384581efb76e08e4a83a5cbcb151"

---


## Mapeo de Payload LoRa

| Campo Doctrinal | C Struct Field | Tipo C | Notas |
| :--- | :--- | :--- | :--- |
| NODE_ID | `node_id` | `uint32_t` | Identificador único del nodo. |
| BATT_LVL | `battery_mv` | `uint16_t` | Nivel de batería en mV. |
| TEMP_INTERNAL | `temp_cx10` | `int16_t` | Temperatura interna en °C * 10. |
| STATE_CODE | `state_code` | `uint8_t` | Código del estado actual (ver `node_states.h`). |
| TIMESTAMP_ISO8601 | `timestamp` | `uint32_t` | Timestamp UNIX (segundos desde Epoch). |

## Ciclo de Operación Implementado
- **Frecuencia de despertar:** 120 minutos (7200 segundos) por defecto.
- **Ventana de escucha:** 30 segundos.
- **Momento de transmisión:** T+35 segundos.

## Referencias Doctrinales
- Ver `docs/HEARTBEAT_v0.1.md`
- Ver `docs/ADRs/ADR-0007-UNIFICACION-HEARTBEAT.md`
