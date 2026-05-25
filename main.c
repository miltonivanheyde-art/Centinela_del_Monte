#include <stdio.h>
#include "node_states.h"
#include "heartbeat.h"
#include "power_manager.h"

/* Globales del sistema */
node_state_t current_state = STATE_INIT;

void setup()
{
    // Placeholder: Inicialización de GPIOs (Ref: PINOUT_v0.1.md)
    printf("Centinela del Monte - Inicializando...\n");
    current_state = STATE_SENSE;
}

void loop()
{
    switch (current_state)
    {
    case STATE_SENSE:
        printf("Estado: SENSE - Leyendo sensores...\n");
        // Placeholder: Lógica SHT31 y ADXL345
        current_state = STATE_TX;
        break;

    case STATE_TX:
        printf("Estado: TX - Enviando Heartbeat...\n");
        process_heartbeat();
        current_state = STATE_SLEEP;
        break;

    case STATE_SLEEP:
        printf("Estado: SLEEP - Entrando en ahorro energético...\n");
        set_peripheral_power(false);
        enter_deep_sleep(120); // 2 horas según ADR-0007
        break;

    case STATE_CRITICAL:
        // Log de error persistente
        break;

    default:
        current_state = STATE_INIT;
        break;
    }
}

int main()
{
    setup();
    while (1)
    {
        loop();
    }
    return 0;
}