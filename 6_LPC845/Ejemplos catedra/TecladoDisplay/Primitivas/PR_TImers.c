/*
 * TImer.c
 *
 *  Created on: 9 sep. 2021
 *      Author: d_lugano
 */

#include <PR_Timers.h>
#include "Systick.h"

uint8_t flagT0=0;
uint8_t flagT1=0;
uint8_t flagT2=0;

void ( * HandlersTimer [CANT_TIMERS]) (void);

void TimerStart(uint8_t ntimer, uint32_t time, void (*handler)(void), uint32_t base)
{
	timers[ntimer]=time*base;
	flagsT[ntimer]=0;
	HandlersTimer[ntimer]=handler;
}

void TimerStop(uint8_t ntimer)
{
	timers[ntimer]=0;
	flagsT[ntimer]=0;
}

void TimerEvent(void)
{
	uint8_t i=0;

	for(i=0; i<CANT_TIMERS; i++)
	{
		if(flagsT[i]==1)
		{
			flagsT[i]=0;
			HandlersTimer[i]();
		}
	}
}

void HandlerT0(void)
{
	flagT0=1;
}

void HandlerT1(void)
{
	flagT1=1;
}

void HandlerT2(void)
{
	flagT2=1;
}
