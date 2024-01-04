/*
 * Timer.h
 *
 *  Created on: 9 sep. 2021
 *      Author: d_lugano
 */

#ifndef PR_TIMERS_H_
#define PR_TIMERS_H_

#include "LPC845.h"
#include "Systick.h"

#define SEG 1000
#define MIN 60000
#define DEC 100
#define MILI 1

//void ( * HandlersTimer [CANT_TIMERS]) (void);

void TimerStart(uint8_t ntimer, uint32_t time, void (*handler)(void), uint32_t base);
void TimerStop(uint8_t ntimer);
void TimerEvent(void);


extern uint8_t flagT0;
extern uint8_t flagT1;
extern uint8_t flagT2;

void HandlerT0(void);
void HandlerT1(void);
void HandlerT2(void);

#endif /* PR_TIMERS_H_ */
