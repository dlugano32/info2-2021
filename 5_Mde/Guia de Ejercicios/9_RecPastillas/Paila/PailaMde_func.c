/*
 * PailaMde_func.c
 *
 *  Created on: 21 jul. 2021
 *      Author: d_lugano
 */

#include "PailaMde_func.h"

void m_InitT0_10min(void)
{
	TimerStart(0, 10, handler0, MIN);
}

void StopT0(void)
{
	TimerStop(0);
}

void handler0(void)
{
	flagT0=1;
}
