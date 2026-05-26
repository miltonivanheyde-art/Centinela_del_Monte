/*
 * @file heartbeat.c
 * @brief Empaqueta y registra el latido doctrinal.
 * @version v0.1
 * @status validated
 * @date 2026-05-21
 * @hash sha256:125e55832d15b21e5b7892d627b1bdba4bbf293bf4d3bafb6bb2ef6d58aa0a1b
 *
 * Ref: docs/HEARTBEAT_v0.1.md
 */

#include "heartbeat.h"
#include "node_states.h"
#include "power_manager.h"
#include "esp_log.h"

#include <time.h>
#include <inttypes.h>

void process_heartbeat(void)
{
    static const char *TAG = "HEARTBEAT";

    heartbeat_payload_t payload;

    /* TODO: Obtener NODE_ID real (NVS/efuse/mac) */
    payload.node_id = 0x12345678;

    payload.battery_mv = get_battery_voltage();
    payload.temp_cx10  = get_internal_temp();
    payload.state_code = (uint8_t)current_state;
    payload.timestamp  = (uint32_t)time(NULL);

    ESP_LOGI(TAG,
             "NodeID=0x%" PRIx32 ", Batt=%u mV, Temp=%d (x0.1C), State=%u, Time=%" PRIu32,
             payload.node_id,
             (unsigned)payload.battery_mv,
             (int)payload.temp_cx10,
             (unsigned)payload.state_code,
             payload.timestamp);

    /* TODO: Integrar transmisión LoRa */
    ESP_LOGI(TAG, "Heartbeat processed");
}
