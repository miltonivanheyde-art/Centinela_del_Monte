/*
 * title: Smoke Test - Power Manager
 * version: v1.0
 * author: Gemini Code Assist
 * status: staging
 * hash: sha256:pending_hash
 */

#include "power_manager.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "SMOKE_TEST";

void app_main(void)
{
    ESP_LOGI(TAG, "Starting Power Manager Smoke Test...");
    power_manager_init();
    set_peripheral_power(true);

    while (1)
    {
        uint16_t vbat = get_battery_voltage();
        int16_t temp = get_internal_temp();

        ESP_LOGI(TAG, "Status -> Vbat: %u mV | Temp: %d.%d C",
                 vbat, temp / 10, abs(temp % 10));

        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}