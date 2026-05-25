---
title: "Especificación de Tests para Protección Térmica"
version: "v0.1"
status: "draft"
author: "Gemini Code Assist"
ia_source: "Gemini PRO"
related_adr: "ADR-0001-FATIGA-TERMICA.md"
date: "2026-05-21"
hash: "sha256:41c1aaff2d21d0479fdb3686dd1cf9cc0ffd5c4fd32f0d0637c18b34821f3937"

---


## Objetivo
Validar la lógica de protección térmica del nodo Centinela según `docs/ADRs/ADR-0001-FATIGA-TERMICA.md` y `firmware/docs/ESTADOS_DEL_NODO_IMPL_v0.1.md`.

## Casos de Prueba (Pseudocódigo C)

### Test 1: Transición a CRITICAL por Temperatura Excesiva
```c
// Precondición: current_state = STATE_SENSE, temperatura < TEMP_THRESHOLD_ALERT
set_current_state(STATE_SENSE);
set_mock_temperature(500); // 50.0°C
run_fsm_iteration();
assert_state_equals(STATE_SENSE); // No cambia

// Precondición: current_state = STATE_SENSE, temperatura > TEMP_THRESHOLD_ALERT
set_mock_temperature(560); // 56.0°C
run_fsm_iteration();
assert_state_equals(STATE_CRITICAL);
```

## Matriz de Validación Térmica
| Temperatura Interna | Estado Actual | Estado Destino Esperado |
| :--- | :--- | :--- |
| `< 55°C` | `STATE_ANY` | `STATE_ANY` (sin cambio por temperatura) |
| `> 55°C` | `STATE_ANY` | `STATE_CRITICAL` |
