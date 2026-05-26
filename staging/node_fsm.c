-- -
/*
 * @title Lógica de la Máquina de Estados (FSM)
 * @version v0.2
 * @status validated
 * @author Gemini Code Assist
 * @ia_source Gemini Code Assist
 * @date 2026-05-25
 * @hash sha256:daa52cc4f3d25f1dada6195601c3df44ee18b1bca1100478c7b29930d8c93577
 * @file node_fsm.c
 * @brief Implementación de la lógica de transiciones de estado.
 * @ref docs/ESTADOS_DEL_NODO_IMPL_v0.1.md
 */

#include <stdlib.h>
#include "node_states.h"
#include "power_manager.h"
#include "esp_log.h"

   static const char *TAG = "FSM";

extern node_state_t current_state;

void run_fsm_iteration(void)
{
    // 1. Validación de seguridad térmica (ADR-0001)
    int16_t temp = get_internal_temp();
    if (temp > 600) // Umbral: 60.0°C
    {
        ESP_LOGE(TAG, "FALLO TERMICO: %d.%d C. Entrando en CRITICAL.", temp / 10, abs(temp % 10));
        current_state = STATE_CRITICAL;
        return;
    }

    // 2. Gestión energética (POWER_STRATEGY)
    uint16_t vbat = get_battery_voltage();
    if (vbat < 3100 && current_state != STATE_RESERVE && current_state != STATE_CRITICAL)
    {
        ESP_LOGW(TAG, "Energia critica: %u mV. Fallback a RESERVA.", vbat);
        current_state = STATE_RESERVE;
    }
}

void handle_panic(void)
{
    ESP_LOGE(TAG, "PANIC: Sistema detenido por fallo critico.");
    while (1)
    {
        // Loop infinito de seguridad
    }
}












