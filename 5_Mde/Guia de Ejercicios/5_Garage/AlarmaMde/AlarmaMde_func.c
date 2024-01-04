/*
 * AlarmaMde_func.c
 *
 *  Created on: 20 jul. 2021
 *      Author: d_lugano
 */
#include "AlarmaMde_func.h"

void m_SirenaON(void)
{
	Buzzer(1);
}

void m_SirenaOff(void)
{
	Buzzer(0);
}

void m_IniciarT0_10s (void)
{
	TimerStart(0, 10, handlerT0(), SEG);
}

void m_StopT0(void)
{
	TimerStop(0);
}

void handlerT0(void)
{
	flagT0=1;
}
