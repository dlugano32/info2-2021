/*
 * DR_teclado.h
 *
 *  Created on: 16 sep. 2021
 *      Author: d_lugano
 */

#ifndef DR_TECLADO_H_
#define DR_TECLADO_H_

#include "../Drivers/DR_GPIO.h"
#include "../Drivers/LPC845.h"

extern uint8_t Tecla;

#define DEBOUNCE_COUNT 20

#define COL1 0,16
#define COL2 0,17
#define COL3 0,18

#define FIL1 0,19
#define FIL2 0,20
#define FIL3 0,21
#define FIL4 0,22

#define SW0 0
#define SW1 1
#define SW2 2
#define SW3 3
#define SW4 4
#define SW5 5
#define SW6 6
#define SW7 7
#define SW8 8
#define SW9 9
#define SWast 10
#define SWhash 11

#define NO_KEY 255

void InitTeclado(void);
void DriverTecladoSW(void);
uint8_t DriverTecladoHW(void);

#endif /* DR_TECLADO_H_ */
