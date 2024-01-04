/*
 * CtrlAccesoMde_func.c
 *
 *  Created on: 22 jul. 2021
 *      Author: d_lugano
 */


#include "CtrlAccesoMde_func.h"

void m_IniciarT0_10s(void)
{
	TimerStart(0, 10, handler0, SEG);
}

void m_stopT0(void)
{
	TimerStop(0);
}

void handler0 (void)
{
	flagT0=1;
}
