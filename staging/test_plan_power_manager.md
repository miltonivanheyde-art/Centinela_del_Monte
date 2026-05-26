# Plan de Pruebas: Power Manager (v0.2)

## Escenarios

1. **Aislamiento Térmico**: Verificar que GPIO 3 pase a LOW inmediatamente antes de entrar en sleep (Validación ADR-0001).
2. **Dual-Wakeup**:
    - Forzar interrupción en GPIO 15 (Simulación Alarma RTC).
    - Esperar timeout de temporizador interno.
3. **Lectura VBat**: Comparar `get_battery_voltage()` con medición de multímetro en el divisor de tensión.

## Criterios de Aceptación

- Consumo en Deep Sleep < 20uA (Hardware real).
- El sistema debe despertar con un flanco de bajada en el pin del RTC.
- No debe haber drift térmico en sensores SHT31 tras 24h de operación cíclica.

## Notas

- Requiere `#define SIMULATE_POWER` para pruebas en CI sin hardware.