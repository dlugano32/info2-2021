/*
 * DR_teclado.h
 *
 *  Created on: 16 sep. 2021
 *      Author: d_lugano
 */

#ifndef DR_TECLADO_H_
#define DR_TECLADO_H_

#include "GPIO.h"
#include "LPC845.h"

extern uint8_t Tecla;

#define DEBOUNCE_COUNT 50

#define PUSH 0
#define NOT_PUSH 1

#define SW_SEL 		0,16
#define SW_LEFT 	0,17
#define SW_DOWN 	0,18
#define SW_UP 		0,19
#define SW_RIGHT 	0,20
#define SW_ST 		0,21

#define SELECT 		16
#define LEFT_ARROW	17
#define DOWN_ARROW	18
#define UP_ARROW	19
#define RIGHT_ARROW 20
#define START		21


#define NO_KEY 255

void InitTeclado(void);
void DriverTecladoSW(void);
uint8_t DriverTecladoHW(void);

#endif /* DR_TECLADO_H_ */
