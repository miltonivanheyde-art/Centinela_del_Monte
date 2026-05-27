#ifndef NODE_STATES_H
#define NODE_STATES_H

#include <stdint.h>

typedef enum
{
    STATE_INIT = 0,
    STATE_IDLE,
    STATE_RESERVE,
    STATE_CRITICAL
} node_state_t;

void run_fsm_iteration(void);
void handle_panic(void);

#endif
