/*
 * DR_Timer.h
 *
 *  Created on: 25 nov. 2021
 *      Author: d_lugano
 */

#ifndef DR_TIMER_H_
#define DR_TIMER_H_

typedef unsigned int uint32_t;

typedef struct
{
	uint32_t CFG;	//0x800AD000
	uint32_t DIV;	//Offset 0x4
	uint32_t VALUE;	//Offset 0x4
}TIMERs;

#define TIMER_BASE 0x800AD000u
#define TIMER ((TIMERs*) TIMER_BASE)

void InitTimer(void);

#endif /* DR_TIMER_H_ */
