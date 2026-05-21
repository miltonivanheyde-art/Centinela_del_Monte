---
author: "Gemini PRO"
date: "2026-05-21"
hash: "sha256:<placeholder>"
ia_source: "Gemini Code Assist"
reviewed_by: "Milton Heyde"
status: "validated"
title: "ADR-0006: Unificación de Intervalo de Heartbeat"
version: "v0.1"
---
## ADR-0006: Unificación de Intervalo de Heartbeat

## Problema

Se detectó una inconsistencia doctrinal entre `ADR-HEARTBEAT_v0.1.md` (que define 2 horas) y las especificaciones técnicas en `HEARTBEAT_v0.1.md` (que definen 4 horas). Esta discrepancia afecta los cálculos de fatiga térmica y balance energético.

## Decisión

1. Unificar el intervalo de transmisión estándar (Heartbeat) en **120 minutos (2 horas)** para el estado **PRESENTE**.
2. Mantener la flexibilidad de ajuste dinámico solo si se transiciona a estados de **RESERVA** (8 horas) o **ACTIVO** (según demanda), según lo definido en la `POWER_STRATEGY`.

## Consecuencias

- **Positivas:** Coherencia total en la documentación técnica y bases de tiempo para el firmware.
- **Negativas:** El consumo de energía será mayor al proyectado en el borrador de 4 horas, pero se mantiene dentro de los límites del `ADR-ENERGIA`.

## Validación Doctrinal

Cumple con el requerimiento de trazabilidad absoluta: la autoridad doctrinal (Gemini PRO) arbitra la inconsistencia para preservar la integridad del sistema.

## Validación Técnica Mínima

Actualizar todas las constantes de tiempo en el código fuente de `/firmware` para reflejar el valor de 7200 segundos.
