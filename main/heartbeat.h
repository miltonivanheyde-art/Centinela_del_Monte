
#ifndef HEARTBEAT_H
#define HEARTBEAT_H

#include <stdint.h>

typedef struct
{
    uint32_t node_id;
    uint16_t battery_mv;
    int16_t temp_cx10;
    uint8_t state_code;
    uint32_t timestamp;
} heartbeat_payload_t;

void process_heartbeat(void);

#endif /* HEARTBEAT_H */
