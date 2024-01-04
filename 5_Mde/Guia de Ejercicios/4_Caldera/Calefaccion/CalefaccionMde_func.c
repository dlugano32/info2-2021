/*
 * CalefaccionMde_func.c
 *
 *  Created on: 20 jul. 2021
 *      Author: d_lugano
 */
#include "CalefaccionMde_func.h"

int getTemperatura(void)
{
	int Temp;

	Temp = -50+ 40*(cuentas*3.3)/4096;

	return Temp;
}

int TempOK(void)
{
	int ret=0;

	if (getTemperatura() >= TEMP_FINAL)
		ret=1;

	return ret;
}

int TempLow(void)
{
	int ret=0;

	if( getTemperatura() <= (TEMP_FINAL - BANDA_HISTERESIS) )
		ret=1;

	return ret;
}

void m_calentadorOff(void)
{
	Relays(0, 0);	//Uso un Relay para desactivar el calentador
}

void m_calentadorON(void)
{
	Relays(0,1);	//Uso un Relay para activar el calentador
}
