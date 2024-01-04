/*
 * AlarmaMde_funciones.c
 *
 *  Created on: 17 jul. 2021
 *      Author: d_lugano
 */


#include "AlarmaMde_funciones.h"


void m_Sirena_off(void)
{
	Buzzer(0);
}

void m_Sirena_on(void)
{
	Buzzer(1);
}

void m_Iniciar_T1_0_5s(void)
{
	TimerStart( 1, 500, handler1, DEC);
}

void m_Stop_T1 (void)
{
	TimerStop(1);
}

void handler1(void)
{
	flag_T1=1;
}
