---
title: "Especificación de Tests para Gestión de Energía"
version: "v0.1"
status: "draft"
author: "Gemini Code Assist"
ia_source: "Gemini PRO"
related_adr: "ADR-0001-FATIGA-TERMICA.md"
date: "2026-05-21"
hash: "sha256:32cf1b2e40d6a4d4e90485e825eb6a5b3b5c5c936012f18ff02e9b84d2f6b2f4"

---


## Objetivo
Validar el comportamiento de la gestión de energía según `docs/POWER_STRATEGY_v0.1.md` y `firmware/docs/POWER_STRATEGY_IMPL_v0.1.md`.

## Casos de Prueba (Pseudocódigo C)

### Test 1: Corte de Energía a Periféricos
```c
// Precondición: Periféricos apagados
set_peripheral_power(false);
assert_gpio_state(GPIO_POWER_ENABLE, LOW);

// Precondición: Periféricos encendidos
set_peripheral_power(true);
assert_gpio_state(GPIO_POWER_ENABLE, HIGH);
```

### Test 2: Transición a Modo Reserva por Batería Baja
```c
// Precondición: current_state = STATE_SENSE, batería > BATT_THRESHOLD_RESERVE_MV
set_current_state(STATE_SENSE);
set_mock_battery_voltage(3200); // 3.2V
run_fsm_iteration();
assert_state_equals(STATE_SENSE); // No cambia

// Precondición: current_state = STATE_SENSE, batería < BATT_THRESHOLD_RESERVE_MV
set_mock_battery_voltage(3000); // 3.0V
run_fsm_iteration();
assert_state_equals(STATE_RESERVE);
```
