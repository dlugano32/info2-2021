/*
 * Timer.h
 *
 *  Created on: 9 sep. 2021
 *      Author: d_lugano
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "../Drivers/LPC845.h"
#include "../Drivers/Systick.h"
#include "../Drivers/Systick.h"

#define SEG 1000
#define MIN 60000
#define DEC 100
#define MILI 1

//void ( * HandlersTimer [CANT_TIMERS]) (void);

extern uint8_t flagT0;

void TimerStart(uint8_t ntimer, uint32_t time, void (*handler)(void), uint32_t base);
void TimerStop(uint8_t ntimer);
void TimerEvent(void);

void HandlerT0(void);

#endif /* TIMER_H_ */
