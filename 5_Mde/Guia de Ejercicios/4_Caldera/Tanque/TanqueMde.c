/*
 * TanqueMde.c
 *
 *  Created on: 20 jul. 2021
 *      Author: d_lugano
 */


#include "TanqueMde.h"
#include "TanqueMde_func.h"

static unsigned char estado=LLENO;

void TanqueMde(void)
{
	switch(estado)
	{
		case VACIO:
			if(s_SensorMin() == 0)
			{
				m_LedAlarmaOff();
				estado=LLENANDO;
			}
			break;

		case LLENO:
			if( s_SensorMin() == 1)
			{
				m_BombaON();
				estado=LLENANDO;
			}
			break;

		case LLENANDO:

			if( s_SensorVacio() == 1)
			{
				m_LedAlarmaON();
				estado=VACIO;
			}

			if( s_SensorLleno() == 0)
			{
				m_BombaOff();
				estado=LLENO;
			}
			break;

		default:
			m_BombaOff();
			estado=LLENO;
	}
}

void init_TanqueMde()
{
	m_BombaOff();
}

int HayAgua(void)	//Si hay agua devuelve 1, si no hay agua devuelve 0
{
	return (estado!=VACIO);
}
