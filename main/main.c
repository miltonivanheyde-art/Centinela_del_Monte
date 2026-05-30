
/*
 * @file main.c
 * @brief Punto de entrada del Nodo Centinela
 * @version v0.1
 * @status draft
 * @date 2026-05-21
 * @hash sha256:pending_hash
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
        /* 1) Ejecutar una iteración de la FSM */
        run_fsm_iteration();

        /* 2) Capturar el estado una sola vez (determinismo y claridad) */
        node_state_t current_state = get_current_state();

        /* 3) Política operacional:
         *    - En estado crítico: detener operación normal y entrar a PANIC
         *    - En estados no críticos: emitir heartbeat operativo
         */
        if (current_state == STATE_CRITICAL)
        {
            ESP_LOGE(TAG, "STATE_CRITICAL -> PANIC");
            handle_panic();
            /* Nota: handle_panic() debería no retornar. Si retorna, el loop sigue. */
        }
        else
        {
            process_heartbeat();
        }

        vTaskDelay(pdMS_TO_TICKS(LOOP_PERIOD_MS));
    }
}
