#ifndef POWER_MANAGER_H
#define POWER_MANAGER_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Obtiene el voltaje actual de la batería en mV.
 * @return Voltaje de la batería en milivoltios.
 * Ref: firmware/docs/POWER_STRATEGY_IMPL_v0.1.md
 */
uint16_t get_battery_voltage(void);

/**
 * @brief Obtiene la temperatura interna del MCU en décimas de grado Celsius.
 * @return Temperatura en décimas de grado Celsius (ej. 255 para 25.5°C).
 * Ref: docs/ADRs/ADR-0001-FATIGA-TERMICA.md
 */
int16_t get_internal_temp(void);

#endif // POWER_MANAGER_H