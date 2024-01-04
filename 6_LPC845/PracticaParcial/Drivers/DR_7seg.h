/*
 * DR_7seg.h
 *
 *  Created on: 17 nov. 2021
 *      Author: d_lugano
 */

#ifndef DR_7SEG_H_
#define DR_7SEG_H_

#include "LPC845.h"

#define N_DIGITOS 6

extern uint8_t DigitoDisplay[N_Digitos];	//Variable global

void BarridoDisplays(void);

#define DIG0 0,0
#define DIG1 0,1
#define DIG2 0,2
#define DIG3 0,3
#define DIG4 0,4
#define DIG5 0,5

#define segA 0,15
#define segB 0,16
#define segC 0,17
#define segD 0,18
#define segE 0,19
#define segF 0,20
#define segG 0,21
#define segDP 0,22

#endif /* DR_7SEG_H_ */

