/*
 * 7seg.h
 *
 *  Created on: 6 oct. 2021
 *      Author: d_lugano
 */

#ifndef PR_7SEG_H_
#define PR_7SEG_H_

#include "LPC845.h"
#include "DR_7seg.h"

//extern uint32_t num_disp;

#define CONTADOR 0
#define TIMER 1

void Display(uint32_t nro_display, uint32_t valor);
void Display_mas(uint32_t numero);
void Display_menos(uint32_t numero);

#endif /* 7SEG_H_ */
