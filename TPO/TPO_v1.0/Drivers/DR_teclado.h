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

#define SW0 0,16
#define SW1 0,17
#define SW2 0,18
#define SW3 0,19
#define SW4 0,20
#define SW5 0,21
#define SW6 0,22
#define SW7 0,23
#define SW8 0,26
#define SW9 0,27

#define SELECT 		16
#define CROSS		17
#define LEFT_ARROW	18
#define TRIANGLE	19
#define DOWN_ARROW	20
#define UP_ARROW	21
#define SQUARE		22
#define RIGHT_ARROW 23
#define CIRCLE 		26
#define START		27


#define NO_KEY 255

void DriverTecladoSW(void);
uint8_t DriverTecladoHW(void);

#endif /* DR_TECLADO_H_ */
