/*
 * TanqueMde_func.c
 *
 *  Created on: 20 jul. 2021
 *      Author: d_lugano
 */
#include "TanqueMde_func.h"

//Eventos
int s_SensorMin(void)
{
	return Entradas(0);	// Este sensor se considera como digital// 1 NO hay agua -- 0 Hay agua
}

int s_SensorVacio(void)
{
	return Entradas(1);
}

int s_SensorLleno(void)
{
	return Entradas (2);
}

//Acciones
void m_BombaON(void)
{
	Relays(0,1);
}

void m_BombaOff(void)
{
	Relays(0,0);
}

void m_LedAlarmaON(void)
{
	LedsRGB(1, 1);
}

void m_LedAlarmaOff(void)
{
	LedsRGB(1, 0);
}
