---
title: "Especificación de Tests para Máquina de Estados (FSM)"
version: "v0.1"
status: "draft"
author: "Gemini Code Assist"
ia_source: "Gemini PRO"
related_adr: "ADR-0002-FLUJO-AUDITORIAS.md"
date: "2026-05-21"
hash: "sha256:f19a0681897a99f9b2a19f8c6f06c1459270783844fb4844558c8d8b3829d286"

---


## Objetivo
Validar las transiciones de estado de la FSM del nodo Centinela según `docs/ESTADOS_DEL_NODO_v0.1.md` y `firmware/docs/ESTADOS_DEL_NODO_IMPL_v0.1.md`.

## Casos de Prueba (Pseudocódigo C)

### Test 1: Transición SENSE -> TX
```c
// Precondición: current_state = STATE_SENSE, temperatura < TEMP_THRESHOLD_ALERT
set_current_state(STATE_SENSE);
set_mock_temperature(200); // 20.0°C
run_fsm_iteration();
assert_state_equals(STATE_TX);
```

### Test 2: Transición SENSE -> ALERT por Temperatura
```c
// Precondición: current_state = STATE_SENSE, temperatura > TEMP_THRESHOLD_ALERT
set_current_state(STATE_SENSE);
set_mock_temperature(600); // 60.0°C
run_fsm_iteration();
assert_state_equals(STATE_CRITICAL); // O STATE_ALERT si la lógica es diferente
```

## Matriz de Transiciones a Validar
| Estado Origen | Condición | Estado Destino Esperado |
| :--- | :--- | :--- |
| `STATE_SENSE` | `temp < TEMP_THRESHOLD_ALERT` | `STATE_TX` |
| `STATE_SENSE` | `temp > TEMP_THRESHOLD_ALERT` | `STATE_CRITICAL` |
| `STATE_TX` | `batt > BATT_THRESHOLD_RESERVE` | `STATE_SLEEP` |
| `STATE_TX` | `batt < BATT_THRESHOLD_RESERVE` | `STATE_RESERVE` |
| `STATE_RESERVE` | `batt > BATT_THRESHOLD_NORMAL` | `STATE_SENSE` |
| `STATE_ANY` | `batt < BATT_THRESHOLD_CRITICAL` | `STATE_CRITICAL` |
