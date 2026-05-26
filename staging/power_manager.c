/*
 * title: Implementación del Gestor de Energía
 * version: v0.6
 * status: validated
 * author: Gemini Code Assist
 * ia_source: Gemini Code Assist
 * date: 2026-05-25
 * hash: sha256:pending_hash
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
#include "driver/rtc_io.h"
#include "driver/adc.h"
#include "driver/temperature_sensor.h"
#include "esp_sleep.h"
#include "esp_adc_cal.h"
#endif

static const char *TAG = "PM";

/* Hardware mapping conforme a PINOUT_v0.1.md */
#define PIN_GPIO_POWER_ENABLE GPIO_NUM_3
#define PIN_GPIO_RTC_INT GPIO_NUM_15
#define ADC_VBAT_CHANNEL ADC1_CHANNEL_1
#define PIN_I2C_SDA GPIO_NUM_4
#define PIN_I2C_SCL GPIO_NUM_5

/**
 * PM_ADC_SCALE: Divisor resistivo 1/2.
 * Calibración: Medir Vbat real vs lectura ADC y ajustar este factor.
 */
#define PM_ADC_SCALE 2.0f

#ifndef SIMULATE_POWER
static esp_adc_cal_characteristics_t adc_chars;
#endif

static void i2c_isolate_pins(void)
{
#ifndef SIMULATE_POWER
    /* Poner bus I2C en High-Z para evitar fugas de corriente en Deep Sleep */
    gpio_set_direction(PIN_I2C_SDA, GPIO_MODE_INPUT);
    gpio_set_direction(PIN_I2C_SCL, GPIO_MODE_INPUT);
    gpio_set_pull_mode(PIN_I2C_SDA, GPIO_FLOATING);
    gpio_set_pull_mode(PIN_I2C_SCL, GPIO_FLOATING);
    ESP_LOGI(TAG, "I2C Isolated (High-Z)");
#endif
}

void power_manager_init(void)
{
#ifndef SIMULATE_POWER
    /* Configurar pin de habilitación de periféricos */
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << PIN_GPIO_POWER_ENABLE),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = 0,
        .pull_down_en = 0,
        .intr_type = GPIO_INTR_DISABLE};
    gpio_config(&io_conf);
    set_peripheral_power(false);

    /* Configurar ADC para monitoreo de batería */
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC_VBAT_CHANNEL, ADC_ATTEN_DB_11);

    /* Inicializar características de calibración */
    esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, 1100, &adc_chars);

    ESP_LOGI(TAG, "Hardware Energy Manager Initialized");
#else
    ESP_LOGI(TAG, "[MOCK] Power Manager Initialized");
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
        ESP_LOGE(TAG, "ADC read failed: %s", esp_err_to_name(err));
        return 0;
    }

    float v_bat_mv = (float)v_adc_mv * PM_ADC_SCALE;
    return (uint16_t)roundf(v_bat_mv);
#endif
}

int16_t get_internal_temp(void)
{
#ifdef SIMULATE_POWER
    return 255; /* 25.5°C */
#else
    static temperature_sensor_handle_t temp_sensor = NULL;
    if (temp_sensor == NULL)
    {
        temperature_sensor_config_t temp_sensor_config = TEMPERATURE_SENSOR_CONFIG_DEFAULT(10, 50);
        temperature_sensor_install(&temp_sensor_config, &temp_sensor);
    }

    float tsens_out;
    temperature_sensor_enable(temp_sensor);
    temperature_sensor_get_temp(temp_sensor, &tsens_out);
    temperature_sensor_disable(temp_sensor);

    return (int16_t)roundf(tsens_out * 10.0f);
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

    /* Verificar capacidad RTC del pin de interrupción */
    if (!rtc_gpio_is_valid_gpio(PIN_GPIO_RTC_INT))
    {
        ESP_LOGE(TAG, "GPIO %d NOT RTC-capable. Wakeup will fail.", PIN_GPIO_RTC_INT);
        /* TODO: En HW v0.2, mover RTC_INT a GPIO 0-21 (RTC domain) */
    }

    esp_sleep_enable_timer_wakeup((uint64_t)duration_min * 60ULL * 1000000ULL);
    esp_sleep_enable_ext0_wakeup(PIN_GPIO_RTC_INT, 0);

    ESP_LOGI(TAG, "Entering Deep Sleep for %u min", (unsigned)duration_min);
    esp_deep_sleep_start();
#else
    ESP_LOGI(TAG, "[MOCK] Deep Sleep entry for %u min", (unsigned)duration_min);
#endif
}