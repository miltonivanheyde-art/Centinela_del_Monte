#ifndef NODE_STATES_H
#define NODE_STATES_H

#include <stdint.h>

typedef enum {
    STATE_INIT = 0,
    STATE_IDLE,
    STATE_RESERVE,
    STATE_CRITICAL
} node_state_t;

/* Estado global (definido en main.c) */
extern node_state_t current_state;

/* FSM API */
void run_fsm_iteration(void);
void handle_panic(void);

#endif /* NODE_STATES_H */
