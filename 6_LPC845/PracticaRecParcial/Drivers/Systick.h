/*
 * Systick.h
 *
 *  Created on: 19 nov. 2021
 *      Author: d_lugano
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "LPC845.h"
extern uint8_t flag500ms;
extern uint8_t flag10seg;
extern uint8_t LedR;
extern uint8_t LedV;

void InitSystick(void);
void Timer10seg(void);

#endif /* SYSTICK_H_ */
