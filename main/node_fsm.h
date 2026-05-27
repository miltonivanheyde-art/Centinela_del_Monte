/*
 * @file node_fsm.h
 * @brief API del modulo FSM del nodo Centinela
 * @version v0.2
 * @status validated
 * @date 2026-05-26
 */

#ifndef NODE_FSM_H
#define NODE_FSM_H

#include "node_states.h"
#include <stdint.h>

/* Inicializacion de la FSM */
void fsm_init(void);

/* Iteracion principal de la maquina de estados */
void run_fsm_iteration(void);

/* Transicion controlada de estado */
void set_state(node_state_t new_state);

/* Consulta del estado actual (evita acceso directo global) */
node_state_t get_current_state(void);

/* Manejo de condiciones criticas */
void handle_panic(void);

#endif /* NODE_FSM_H */
