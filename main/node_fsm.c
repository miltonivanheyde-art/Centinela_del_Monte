/*
 * @file node_fsm.c
 * @brief Lógica de la máquina de estados del nodo Centinela
 * @version v0.2
 * @status validated
 * @date 2026-05-25
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdlib.h>
#include "node_states.h"
#include "power_manager.h"
#include "esp_log.h"

static const char *TAG = "FSM";

/* Umbrales */
#define TEMP_CRITICAL_THRESHOLD 600 // 60.0°C
#define VBAT_RESERVE_THRESHOLD 3100 // mV
#define VBAT_HYSTERESIS 100         // mV

void run_fsm_iteration(void)
{
    int16_t temp = get_internal_temp();

    /* Protección térmica (prioridad absoluta) */
    if (temp > TEMP_CRITICAL_THRESHOLD)
    {
        ESP_LOGE(TAG, "CRITICAL: Temp = %d.%d C", temp / 10, abs(temp % 10));
        current_state = STATE_CRITICAL;
        return;
    }

    uint16_t vbat = get_battery_voltage();

    switch (current_state)
    {
    case STATE_INIT:
        ESP_LOGI(TAG, "INIT -> IDLE");
        current_state = STATE_IDLE;
        break;

    case STATE_IDLE:
        if (vbat < VBAT_RESERVE_THRESHOLD)
        {
            ESP_LOGW(TAG, "Low battery: %u mV -> RESERVE", vbat);
            current_state = STATE_RESERVE;
        }
        break;

    case STATE_RESERVE:
        if (vbat >= (VBAT_RESERVE_THRESHOLD + VBAT_HYSTERESIS))
        {
            ESP_LOGI(TAG, "Battery recovered: %u mV -> IDLE", vbat);
            current_state = STATE_IDLE;
        }
        break;

    case STATE_CRITICAL:
        /* Estado terminal: no se sale automáticamente */
        break;

    default:
        ESP_LOGE(TAG, "Unknown state, resetting to INIT");
        current_state = STATE_INIT;
        break;
    }
}

void handle_panic(void)
{
    ESP_LOGE(TAG, "PANIC: System halted");

#ifndef SIMULATE_POWER
    set_peripheral_power(false);
#endif

    /* Loop infinito controlado */
    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}