/*
 * DR_teclado.h
 *
 *  Created on: 16 sep. 2021
 *      Author: d_lugano
 */

#ifndef DR_TECLADO_H_
#define DR_TECLADO_H_

#include "LPC845.h"
#include "GPIO.h"

extern uint8_t Tecla;

#define DEBOUNCE_COUNT 20

#define PUSH 0
#define NO_KEY 1

void DriverTecladoSW(void);

#endif /* DR_TECLADO_H_ */
