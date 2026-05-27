/*
 * @file node_fsm.c
 * @brief Lógica de la máquina de estados del nodo Centinela
 * @version v0.2
 * @status validated
 * @date 2026-05-21
 * @hash sha256:pending_hash
 *
 * Reglas:
 * - Sin YAML
 * - Sin duplicación
 * - Código determinista
 */

#include <stdlib.h>
#include "node_fsm.h"
#include "power_manager.h"
#include "esp_log.h"

static const char *TAG = "FSM";

/* Umbrales provisionales (ajustar con mediciones reales) */
#define TEMP_CRITICAL_THRESHOLD 600 // 60.0°C
#define VBAT_RESERVE_THRESHOLD 3100 // mV

static node_state_t current_state = STATE_INIT;

void fsm_init(void)
{
    set_state(STATE_INIT);
}

void set_state(node_state_t new_state)
{
    current_state = new_state;
}

node_state_t get_current_state(void)
{
    return current_state;
}

void run_fsm_iteration(void)
{
    int16_t temp = get_internal_temp();
    if (temp > TEMP_CRITICAL_THRESHOLD)
    {
        ESP_LOGE(TAG, "CRITICAL: Temp = %d.%d C", temp / 10, abs(temp % 10));
        set_state(STATE_CRITICAL);
        return;
    }

    uint16_t vbat = get_battery_voltage();
    if (vbat < VBAT_RESERVE_THRESHOLD &&
        get_current_state() != STATE_RESERVE &&
        get_current_state() != STATE_CRITICAL)
    {
        ESP_LOGW(TAG, "Low battery: %u mV -> RESERVE", (unsigned)vbat);
        set_state(STATE_RESERVE);
    }
}

void handle_panic(void)
{
    ESP_LOGE(TAG, "PANIC: System halted");

#ifndef SIMULATE_POWER
    set_peripheral_power(false);
#endif

    while (1)
    {
        /* loop intencional de seguridad */
    }
}
