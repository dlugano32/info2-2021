/*
 * IntExt.h
 *
 *  Created on: 9 sep. 2021
 *      Author: d_lugano
 */

#ifndef INTEXT_H_
#define INTEXT_H_

#include "LPC845.h"
#include "gpio.h"

#define FUENTE_INT_0 0
#define FUENTE_INT_1 1

extern uint8_t i;
extern uint8_t flagAscendente;
extern uint8_t flagDescendente;

void InitIntExt(void);

#endif /* INTEXT_H_ */
