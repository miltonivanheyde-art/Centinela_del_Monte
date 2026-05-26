/*
 * title: Contrato de Gestión de Energía
 * version: v0.6
 * status: validated
 * author: Gemini Code Assist
 * ia_source: Gemini Code Assist
 * date: 2026-05-25
 * hash: sha256:pending_hash
 */

/**
 * @file power_manager.h
 * @brief Contrato canónico de la capa energética del Nodo Centinela.
 */

#ifndef POWER_MANAGER_H
#define POWER_MANAGER_H

#include <stdint.h>
#include <stdbool.h>

/** @brief Inicializa periféricos de potencia (ADC y GPIO Control). */
void power_manager_init(void);

/** @brief Obtiene el voltaje de batería en mV. */
uint16_t get_battery_voltage(void);

/** @brief Obtiene temp interna del MCU en décimas de °C */
int16_t get_internal_temp(void);

/** @brief Controla el MOSFET de sensores (ADR-0001) */
void set_peripheral_power(bool on);

/** @brief Entra en Deep Sleep con despertar por RTC/Timer */
void enter_deep_sleep(uint32_t duration_min);

#endif // POWER_MANAGER_H