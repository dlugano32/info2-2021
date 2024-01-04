/*
 * DR_7seg.h
 *
 *  Created on: 5 oct. 2021
 *      Author: d_lugano
 */

#ifndef DR_7SEG_H_
#define DR_7SEG_H_

#include "LPC845.h"
#include "DR_GPIO.h"

#define N_DIGITOS 2

#define segA 0,26
#define segB 0,27
#define segC 0,28
#define segD 0,29
#define segE 0,13
#define segF 0,14
#define segG 0,15

#define DIG0 0,0
#define DIG1 0,1

#define DIGITO_0 0
#define DIGITO_1 1

#define DIG_OFF 1
#define DIG_ON 0

extern uint8_t Digito_Display[N_DIGITOS];

void Init7seg(void);
void BarridoDisplay(void);

#endif /* DR_7SEG_H_ */
