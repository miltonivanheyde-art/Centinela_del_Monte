---
title: "Estrategia de Gestión de Potencia - Derivación de Implementación"
version: "v0.1"
status: "draft"
author: "Gemini Code Assist"
ia_source: "Gemini PRO"
derived_from: "docs/POWER_STRATEGY_v0.1.md"
related_adr: "ADR-0001-FATIGA-TERMICA.md"
date: "2026-05-21"
hash: "sha256:7b8616d17e0a590c25cf53c754bca3de32e3ab0156d181f99ae7e135b231e2eb"

---


## Umbrales de Batería (LiFePO4)
- `BATT_THRESHOLD_NORMAL_MV`: > 3400 mV (70% aprox.)
- `BATT_THRESHOLD_SAVE_MV`: 3100 mV - 3400 mV (30% - 70% aprox.)
- `BATT_THRESHOLD_RESERVE_MV`: 2900 mV - 3100 mV (< 15% aprox.)
- `BATT_THRESHOLD_CRITICAL_MV`: < 2900 mV (Corte de seguridad)

## Modos de Operación y Comportamiento
| Modo Doctrinal | C State | Comportamiento Implementado |
| :--- | :--- | :--- |
| Normal | `STATE_SENSE` | Lectura completa de sensores, Heartbeat estándar. |
| Ahorro | `STATE_SENSE` | Reducción de frecuencia de sensores secundarios. |
| Reserva | `STATE_RESERVE` | Heartbeat cada 8 horas, sensores apagados. |
| Crítico | `STATE_CRITICAL` | Apagado de seguridad, log de error. |

## Control de Periféricos
- **GPIO 3 (`POWER_ENABLE_PIN`):** Controla MOSFET para corte de energía a sensores.
  - `set_peripheral_power(true)`: GPIO 3 HIGH.
  - `set_peripheral_power(false)`: GPIO 3 LOW.

## Referencias Doctrinales
- Ver `docs/POWER_STRATEGY_v0.1.md`
- Ver `docs/ADRs/ADR-0001-FATIGA-TERMICA.md`
