-- -title : "Implementación del Gestor de Energía" version : "v0.6" status : "validated" author : "Gemini Code Assist" ia_source : "Gemini Code Assist" date : "2026-05-21" hash : "sha256:49c0604869680373801869680373801869680373801869680373801869680373" -- - -- -title : "Implementación del Gestor de Energía" version : "v0.6" status : "validated" author : "Gemini Code Assist" ia_source : "Gemini Code Assist" date : "2026-05-21" hash : "sha256:49c0604869680373801869680373801869680373801869680373801869680373" -- -
/*
 * title: Implementación del Gestor de Energía
 * version: v0.6
 * status: validated
 * author: Gemini Code Assist
 * ia_source: Gemini Code Assist
 * date: 2026-05-21
 * hash: sha256:49c0604869680373801869680373801869680373801869680373801869680373
 */

/**
 * @file power_manager.c
 * @brief Gestión determinística de energía para ESP32-S3.
 */

#include "power_manager.h"
#include <math.h>
#include "esp_log.h"

#ifndef SIMULATE_POWER
#include "driver/gpio.h"
#include "driver/adc.h"
#include "esp_sleep.h"
#include "esp_adc_cal.h"
#endif

                                                                                                                                                                                                                                                                                                                                                                                                                                                     static const char *TAG = "PM";

/* Configuración de Hardware conforme a PINOUT_v0.1.md */
#define PIN_GPIO_POWER_ENABLE GPIO_NUM_3
#define PIN_GPIO_RTC_INT GPIO_NUM_15
#define ADC_VBAT_CHANNEL ADC1_CHANNEL_1
#define PIN_I2C_SDA GPIO_NUM_4
#define PIN_I2C_SCL GPIO_NUM_5
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
    ESP_LOGI(TAG, "Bus I2C aislado.");
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
    adc1_config_channel_atten(ADC_VBAT_CHANNEL, ADC_ATTEN_DB_11);
    esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, 1100, &adc_chars);
    ESP_LOGI(TAG, "Hardware inicializado.");
#else
    ESP_LOGI(TAG, "[MOCK] Power Manager inicializado.");
#endif
}

uint16_t get_battery_voltage(void)
{
#ifdef SIMULATE_POWER
    return 3750;
#else
    int raw = adc1_get_raw(ADC_VBAT_CHANNEL);
    uint32_t voltage_mv = esp_adc_cal_raw_to_voltage(raw, &adc_chars);
    return (uint16_t)roundf((float)voltage_mv * PM_ADC_SCALE);
#endif
}

int16_t get_internal_temp(void)
{
#ifdef SIMULATE_POWER
    return 255;
#else
    ESP_LOGW(TAG, "get_internal_temp() no implementado para esta version de IDF.");
    return 0;
#endif
}

void set_peripheral_power(bool on)
{
#ifndef SIMULATE_POWER
    gpio_reset_pin(PIN_GPIO_POWER_ENABLE);
    gpio_set_direction(PIN_GPIO_POWER_ENABLE, GPIO_MODE_OUTPUT);
    gpio_set_level(PIN_GPIO_POWER_ENABLE, on ? 1 : 0);
#endif
    ESP_LOGI(TAG, "Peripheral Power: %s", on ? "ON" : "OFF");
}

void enter_deep_sleep(uint32_t duration_min)
{
#ifndef SIMULATE_POWER
    i2c_isolate_pins();
    set_peripheral_power(false);
    esp_sleep_enable_timer_wakeup((uint64_t)duration_min * 60 * 1000000);
    esp_sleep_enable_ext0_wakeup(PIN_GPIO_RTC_INT, 0);
    ESP_LOGI(TAG, "Entrando en Deep Sleep por %u min.", duration_min);
    esp_deep_sleep_start();
#else
    ESP_LOGI(TAG, "[MOCK] Entrando en Deep Sleep por %u min.", duration_min);
#endif
}