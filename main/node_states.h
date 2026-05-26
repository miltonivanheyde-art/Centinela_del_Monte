/*
 * @file node_states.h
 * @brief Definiciones de estados y API de la FSM Centinela
 * @version v0.2
 * @status validated
 * @date 2026-05-25
 */

#ifndef NODE_STATES_H
#define NODE_STATES_H

#include <stdint.h>

/* Definición de estados del nodo */
typedef enum
{
    STATE_INIT = 0,
    STATE_IDLE,
    STATE_RESERVE,
    STATE_CRITICAL
} node_state_t;

/* Estado global (definido en main.c) */
extern node_state_t current_state;

/* API de la FSM */
void run_fsm_iteration(void);
void handle_panic(void);

#endif /* NODE_STATES_H */