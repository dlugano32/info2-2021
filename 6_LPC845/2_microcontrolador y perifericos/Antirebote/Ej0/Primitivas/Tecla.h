/*
 * Tecla.h
 *
 *  Created on: 26 ago. 2021
 *      Author: d_lugano
 */

#ifndef TECLA_H_
#define TECLA_H_

#include "LPC845.h"

#define BOTON_STICK 0, 4

#define PUSH 0
#define NOT_PUSH 1

extern uint8_t Tecla;

uint32_t getKey(void);

#endif /* TECLA_H_ */
