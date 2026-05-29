/*
 * @file main.c
 * @brief Punto de entrada del Nodo Centinela
 * @version v0.1
 * @status validated
 * @date 2026-05-21
 * @hash sha256:c942070f4f13b3ebd7d4053550e766f07be946336f7b5beb072b293c4a5e67bd
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
#include "node_fsm.h"
#include "heartbeat.h"

static const char *TAG = "MAIN";

/* Periodo de ciclo (ms) */
#define LOOP_PERIOD_MS 1000

void app_main(void)
{
    ESP_LOGI(TAG, "Centinela del Monte - Booting");

    power_manager_init();
    set_state(STATE_IDLE);

    while (1)
    {
        run_fsm_iteration();

        /* ejemplo: emitir heartbeat en estados no críticos */
        if (get_current_state() != STATE_CRITICAL)
        {
            process_heartbeat();
        }

        if (get_current_state() == STATE_CRITICAL)
        {
            ESP_LOGE(TAG, "STATE_CRITICAL -> PANIC");
            handle_panic();
        }

        vTaskDelay(pdMS_TO_TICKS(LOOP_PERIOD_MS));
    }
}

