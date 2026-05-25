#include "power_manager.h"
#include "node_states.h" // Para set_peripheral_power, enter_deep_sleep
#include <stdio.h>       // Para printf

// TODO: Definir PIN_GPIO_POWER_ENABLE y PIN_GPIO_RTC_INT según hardware/PINOUT_v0.1.md
#define PIN_GPIO_POWER_ENABLE 3
#define PIN_GPIO_RTC_INT 15

/**
 * @brief Simula la lectura del voltaje de la batería.
 * Ref: hardware/PINOUT_v0.1.md (VBat Monitor en GPIO 2)
 * Ref: firmware/docs/POWER_STRATEGY_IMPL_v0.1.md
 */
uint16_t get_battery_voltage(void)
{
    // TODO: Implementar lectura ADC real de GPIO 2
    // Por ahora, simulación para pruebas
    static uint16_t simulated_voltage = 3600; // Start at 3.6V
    if (simulated_voltage > 2800)
    {
        simulated_voltage -= 10; // Simulate discharge
    }
    return simulated_voltage;
}

/**
 * @brief Simula la lectura de la temperatura interna del MCU.
 * Ref: docs/ADRs/ADR-0001-FATIGA-TERMICA.md
 */
int16_t get_internal_temp(void)
{
    // TODO: Implementar lectura de sensor de temperatura interno del ESP32
    // Por ahora, simulación
    return 250; // 25.0°C
}

/**
 * @brief Controla la alimentación de periféricos externos.
 * Ref: docs/ADRs/ADR-0001-FATIGA-TERMICA.md
 */
void set_peripheral_power(bool on)
{
    // TODO: Implementar control de GPIO_POWER_ENABLE
    printf("Periféricos: %s\n", on ? "ENCENDIDOS" : "APAGADOS");
}

void enter_deep_sleep(uint32_t duration_min)
{
    // TODO: Configurar RTC para despertar en duration_min. Ref: hardware/PINOUT_v0.1.md (RTC SQW/INT en GPIO 15)
    printf("Entrando en Deep Sleep por %u minutos...\n", duration_min);
    // esp_deep_sleep_enable_ext0_wakeup(PIN_GPIO_RTC_INT, 0); // Ejemplo ESP-IDF
    // esp_deep_sleep_start();
}