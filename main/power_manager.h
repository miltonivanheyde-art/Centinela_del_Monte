/*
 * @file power_manager.h
 * @brief Contrato de la capa de gestión de energía
 * @version v0.6
 * @status validated
 * @date 2026-05-21
 * @hash sha256:72e674ca4401c302bb17abb50d91b76893f51b788a9b86a38fd80c3c7bf03f40
 *
 * Reglas:
 * - Sin YAML en headers
 * - Sin duplicación
 * - API mínima y determinista
 */

#ifndef POWER_MANAGER_H
#define POWER_MANAGER_H

#include <stdint.h>
#include <stdbool.h>

void power_manager_init(void);

uint16_t get_battery_voltage(void);

int16_t get_internal_temp(void);

void set_peripheral_power(bool on);

void enter_deep_sleep(uint32_t duration_min);

#endif /* POWER_MANAGER_H */








































