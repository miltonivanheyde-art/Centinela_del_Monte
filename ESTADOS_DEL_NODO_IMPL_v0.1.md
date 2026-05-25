---
title: "Máquina de Estados - Derivación de Implementación"
version: "v0.1"
status: "draft"
author: "Gemini Code Assist"
ia_source: "Gemini PRO"
derived_from: "docs/ESTADOS_DEL_NODO_v0.1.md"
related_adr: "ADR-0001-FATIGA-TERMICA.md"
date: "2026-05-21"
hash: "sha256:43c446daf9fdee7c3f839614a84df45750ceae7df8596f1512709e928c46f3b2"

---


## Mapeo de Estados Doctrinales a Código

| Doctrinal | C Enum | Acción Implementada |
| :--- | :--- | :--- |
| INIT | `STATE_INIT` | `setup_peripherals()`: Configura GPIO, I2C, SPI. |
| SENSE | `STATE_SENSE` | `read_sensors()`: Energiza bus (GPIO3), delay(50), I2C Read. |
| TX | `STATE_TX` | `transmit_lora()`: Empaqueta Payload, SX1262 Send. |
| SLEEP | `STATE_SLEEP` | `enter_deep_sleep()`: Deshabilita periféricos, RTC Alarm. |
| RESERVE | `STATE_RESERVE` | Modo degradado: Solo Heartbeat cada 8h. |
| ALERT | `STATE_ALERT` | Transmisión inmediata por sabotaje o umbral crítico. |
| CRITICAL | `STATE_CRITICAL` | `handle_panic()`: Log en NVS, espera reset físico. |

## Pseudocódigo de Transición (FSM Principal)
```c
switch(current_state) {
    case STATE_SENSE:
        if (temperature > TEMP_THRESHOLD_ALERT) current_state = STATE_ALERT;
        else current_state = STATE_TX;
        break;
    case STATE_TX:
        if (battery_level < BATT_THRESHOLD_RESERVE) current_state = STATE_RESERVE;
        else current_state = STATE_SLEEP;
        break;
}
```

## Thresholds Técnicos
- `TEMP_THRESHOLD_ALERT`: 55°C (Histerésis 2°C).
- `BATT_THRESHOLD_RESERVE`: 3.1V (LiFePO4).
- `BATT_THRESHOLD_CRITICAL`: 2.9V (Corte inmediato).

## Referencias Doctrinales
- Ver `docs/ESTADOS_DEL_NODO_v0.1.md`
- Ver `docs/ADRs/ADR-0001-FATIGA-TERMICA.md`
