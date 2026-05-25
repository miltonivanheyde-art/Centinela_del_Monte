#include "node_states.h"
#include "power_manager.h"
#include <stdio.h>

extern node_state_t current_state;

/**
 * @brief Lógica de transiciones basada en doctrina técnica
 */
void run_fsm_iteration(void)
{
    // 1. Validación de seguridad térmica (ADR-0001)
    if (get_internal_temp() > 600)
    { // 60.0°C
        current_state = STATE_CRITICAL;
    }

    // 2. Fallback energético (POWER_STRATEGY)
    uint16_t vbat = get_battery_voltage();
    if (vbat < 3100 && current_state != STATE_RESERVE)
    {
        current_state = STATE_RESERVE;
    }
}

void handle_panic(void)
{
    // TODO: Implementar registro en NVS antes de halt
    while (1)
    {
        // Watchdog reset preventer or system halt
    }
}