/*
 * @file heartbeat.c
 * @brief Empaqueta y registra el latido doctrinal.
 * @version v0.2
 * @status validated
 * @date 2026-05-25
 */

#include "heartbeat.h"
#include "node_states.h"
#include "power_manager.h"
#include "esp_log.h"
#include "esp_timer.h"
#include <inttypes.h>

static const char *TAG = "HEARTBEAT";

void process_heartbeat(void)
{
    heartbeat_payload_t payload;

    /* TODO: Obtener NODE_ID real (NVS/efuse/mac) */
    payload.node_id = 0x12345678;

    payload.battery_mv = get_battery_voltage();
    payload.temp_cx10 = get_internal_temp();
    payload.state_code = (uint8_t)current_state;

    /* timestamp determinista: segundos desde arranque */
    payload.timestamp = (uint32_t)(esp_timer_get_time() / 1000000);

    ESP_LOGI(TAG,
             "NodeID=0x%" PRIx32 ", Batt=%u mV, Temp=%d (x0.1C), State=%u, Time=%" PRIu32,
             payload.node_id,
             payload.battery_mv,
             payload.temp_cx10,
             payload.state_code,
             payload.timestamp);

    ESP_LOGI(TAG, "Heartbeat processed");
}
