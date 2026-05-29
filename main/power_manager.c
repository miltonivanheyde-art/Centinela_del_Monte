/*
 * @file power_manager.c
 * @brief Gestión determinística de energía para ESP32-S3.
 * @version v0.6
 * @status validated
 * @date 2026-05-21
 * @hash sha256:a8347198ed9a11fa5160e93bb89382f2285043373a3437df3be8ad75e45a0e2b
 *
 * Reglas:
 * - Sin YAML en código
 * - Sin duplicación
 * - Determinismo
 */

#include "power_manager.h"
#include <math.h>
#include "esp_log.h"

#ifndef SIMULATE_POWER
#include "driver/rtc_io.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "esp_sleep.h"
#include "esp_adc_cal.h"
#endif

static const char *TAG = "PM";

/* Hardware mapping (ajustar según PINOUT real) */
#define PIN_GPIO_POWER_ENABLE GPIO_NUM_3
#define PIN_GPIO_RTC_INT GPIO_NUM_15
#define ADC_VBAT_CHANNEL ADC1_CHANNEL_1
#define ADC_VBAT_ATTEN ADC_ATTEN_DB_12
#define PIN_I2C_SDA GPIO_NUM_4
#define PIN_I2C_SCL GPIO_NUM_5

/**
 * PM_ADC_SCALE: Divisor resistivo 1/2.
 * Procedimiento de calibración:
 * 1. Medir Vbat real en bornes con multímetro.
 * 2. Obtener lectura ADC (v_adc_mv).
 * 3. PM_ADC_SCALE = Vbat_real_mv / v_adc_mv.
 */
#define PM_ADC_SCALE 2.0f

#ifndef SIMULATE_POWER
static esp_adc_cal_characteristics_t adc_chars;
#endif

static void i2c_isolate_pins(void)
{
#ifndef SIMULATE_POWER
    gpio_set_direction(PIN_I2C_SDA, GPIO_MODE_INPUT);
    gpio_set_direction(PIN_I2C_SCL, GPIO_MODE_INPUT);

    gpio_set_pull_mode(PIN_I2C_SDA, GPIO_FLOATING);
    gpio_set_pull_mode(PIN_I2C_SCL, GPIO_FLOATING);

    ESP_LOGI(TAG, "I2C isolated (High-Z)");
#endif
}

void power_manager_init(void)
{
#ifndef SIMULATE_POWER
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << PIN_GPIO_POWER_ENABLE),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = 0,
        .pull_down_en = 0,
        .intr_type = GPIO_INTR_DISABLE};

    gpio_config(&io_conf);
    set_peripheral_power(false);

    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC_VBAT_CHANNEL, ADC_VBAT_ATTEN);

    esp_adc_cal_characterize(
        ADC_UNIT_1,
        ADC_VBAT_ATTEN,
        ADC_WIDTH_BIT_12,
        1100,
        &adc_chars);

    ESP_LOGI(TAG, "Power Manager initialized (HW)");
#else
    ESP_LOGI(TAG, "[MOCK] Power Manager initialized");
#endif
}

uint16_t get_battery_voltage(void)
{
#ifdef SIMULATE_POWER
    return 3750;
#else
    uint32_t v_adc_mv = 0;
    esp_err_t err = esp_adc_cal_get_voltage(ADC_VBAT_CHANNEL, &adc_chars, &v_adc_mv);
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "Error lectura ADC: %s", esp_err_to_name(err));
        return 0;
    }

    float v_bat_mv = (float)v_adc_mv * (float)PM_ADC_SCALE;
    return (uint16_t)roundf(v_bat_mv);
#endif
}

int16_t get_internal_temp(void)
{
#ifdef SIMULATE_POWER
    return 255; // 25.5°C
#else
    /* Stub seguro temporal: TSENS desactivado por compatibilidad ESP-IDF 5.3.1 */
    ESP_LOGW(TAG, "Internal temp sensor disabled; returning stub value");
    return 250; // 25.0°C
#endif
}

void set_peripheral_power(bool on)
{
#ifndef SIMULATE_POWER
    gpio_set_level(PIN_GPIO_POWER_ENABLE, on ? 1 : 0);
#endif
    ESP_LOGI(TAG, "Peripheral Power: %s", on ? "ON" : "OFF");
}

void enter_deep_sleep(uint32_t duration_min)
{
#ifndef SIMULATE_POWER
    i2c_isolate_pins();
    set_peripheral_power(false);

    if (!rtc_gpio_is_valid_gpio(PIN_GPIO_RTC_INT))
    {
        ESP_LOGE(TAG, "GPIO %d no es RTC-capable. Deep sleep fallará.", PIN_GPIO_RTC_INT);
        /* TODO: Proponer cambio a GPIO 0-21 en PINOUT_v0.2.md */
    }

    esp_sleep_enable_timer_wakeup((uint64_t)duration_min * 60ULL * 1000000ULL);
    esp_sleep_enable_ext0_wakeup(PIN_GPIO_RTC_INT, 0);

    ESP_LOGI(TAG, "Entering deep sleep: %u min", (unsigned)duration_min);
    esp_deep_sleep_start();
#else
    ESP_LOGI(TAG, "[MOCK] Deep sleep: %u min", (unsigned)duration_min);
#endif
}

