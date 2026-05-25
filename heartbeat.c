#include "heartbeat.h"
#include "node_states.h"   // Para current_state
#include "power_manager.h" // Para get_battery_voltage, get_internal_temp
#include <stdio.h>         // Para printf
#include <time.h>          // Para timestamp

/**
 * @brief Empaqueta y transmite el latido doctrinal.
 * Ref: docs/HEARTBEAT_v0.1.md
 * Ref: firmware/docs/HEARTBEAT_IMPL_v0.1.md
 */
void process_heartbeat(void)
{
    heartbeat_payload_t payload;

    // TODO: Obtener NODE_ID real
    payload.node_id = 0x12345678;
    payload.battery_mv = get_battery_voltage();
    payload.temp_cx10 = get_internal_temp();
    payload.state_code = (uint8_t)current_state;
    payload.timestamp = (uint32_t)time(NULL); // UNIX timestamp

    printf("Heartbeat: NodeID=0x%lX, Batt=%u mV, Temp=%d (x0.1C), State=%u, Time=%lu\n",
           payload.node_id, payload.battery_mv, payload.temp_cx10, payload.state_code, payload.timestamp);

    // TODO: Implementar lógica de transmisión LoRaWAN (SX1262)
    // Ref: hardware/PINOUT_v0.1.md (SPI bus para SX1262)
    // transmit_lora_packet(&payload, sizeof(payload));

    printf("Heartbeat transmitido.\n");
}