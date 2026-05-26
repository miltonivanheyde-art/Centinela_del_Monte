/*
 * @file main.c
 * @brief Punto de entrada del Nodo Centinela
 * @version v0.1
 * @status validated
 * @date 2026-05-21
 * @hash sha256:bccd927f414d01a9300b0c1a097c754f733628fa8c2a71af6ca09a21de3e2ca1
 *
 * Reglas:
 * - Sin YAML
 * - Sin duplicación
 * - Determinismo
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "power_manager.h"
#include "node_states.h"
#include "heartbeat.h"

static const char *TAG = "MAIN";

/* Periodo de ciclo (ms) */
#define LOOP_PERIOD_MS 1000

/* Estado global requerido por node_fsm.c */
node_state_t current_state = STATE_INIT;

void app_main(void)
{
    ESP_LOGI(TAG, "Centinela del Monte - Booting");

    power_manager_init();
    current_state = STATE_IDLE;

    while (1)
    {
        run_fsm_iteration();

        /* ejemplo: emitir heartbeat en estados no críticos */
        if (current_state != STATE_CRITICAL)
        {
            process_heartbeat();
        }

        if (current_state == STATE_CRITICAL)
        {
            ESP_LOGE(TAG, "STATE_CRITICAL -> PANIC");
            handle_panic();
        }

        vTaskDelay(pdMS_TO_TICKS(LOOP_PERIOD_MS));
    }
}
