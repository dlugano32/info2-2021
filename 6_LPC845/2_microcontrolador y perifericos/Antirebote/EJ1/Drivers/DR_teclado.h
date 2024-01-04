/*
 * DR_teclado.h
 *
 *  Created on: 16 sep. 2021
 *      Author: d_lugano
 */

#ifndef DR_TECLADO_H_
#define DR_TECLADO_H_

#include "LPC845.h"
#include "gpio.h"

extern uint8_t Tecla;

#define DEBOUNCE_COUNT 20

#define PUSH 0
#define NOT_PUSH 1

#define SW0 0
#define SW1 1
#define SW2 6
#define NO_KEY 255

void DriverTecladoSW(void);
uint8_t DriverTecladoHW(void);

#endif /* DR_TECLADO_H_ */
