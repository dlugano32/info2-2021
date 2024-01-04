/*
 * Systick.h
 *
 *  Created on: 16 nov. 2021
 *      Author: d_lugano
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "LPC845.h"

void InitSystick(void);
void SysTick_Handler(void);

#endif /* SYSTICK_H_ */
