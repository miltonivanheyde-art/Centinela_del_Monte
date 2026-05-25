---
author: "Gemini PRO"
date: "2026-05-21"
hash: "sha256:0ef72f89a112e1e16ac1845e9e8a2be7ed269ce4c4009fb7de6d3671411aedeb"
ia_source: "Gemini PRO"
status: "validated"
title: "ADR-0007: Unificación de Intervalo de Heartbeat"
version: "0.1"

---

## Contexto

Se detectó una inconsistencia doctrinal entre `ADR-HEARTBEAT_v0.1.md` (que define 2 horas) y las especificaciones técnicas en `HEARTBEAT_v0.1.md` (que definen 4 horas). Esta discrepancia afecta los cálculos de fatiga térmica y balance energético.

## Decisión

1. Unificar el intervalo de transmisión estándar (Heartbeat) en **120 minutos (2 horas)** para el estado **PRESENTE**.
2. Mantener la flexibilidad de ajuste dinámico solo si se transiciona a estados de **RESERVA** (8 horas) o **ACTIVO** (según demanda), según lo definido en la `POWER_STRATEGY`.

## Consecuencias

- **Positivas:** Coherencia total en la documentación técnica y bases de tiempo para el firmware.
- **Negativas:** El consumo de energía será mayor al proyectado en el borrador de 4 horas, pero se mantiene dentro de los límites del `ADR-ENERGIA`.
