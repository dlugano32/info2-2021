/*
 * DR_USARTs.h
 *
 *  Created on: 17 nov. 2021
 *      Author: d_lugano
 */

#ifndef DR_USARTS_H_
#define DR_USARTS_H_

#include "LPC845.h"

#define CLK 30000000
#define TAM_BUFRX1 64

extern uint8_t BufferRx1[TAM_BUFRX1];

void InitUSART1(void);
void PushRx1(uint8_t dato);
int16_t PopRx1(void);

#endif /* DR_USARTS_H_ */
