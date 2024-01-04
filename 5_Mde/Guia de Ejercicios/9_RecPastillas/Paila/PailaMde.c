/*
 * PailaMde.c
 *
 *  Created on: 21 jul. 2021
 *      Author: d_lugano
 */

#include "PailaMde.h"
#include "PailaMde_func.h"
#include "../EntradasSalidas/EntradasSalidas.h"

int flagT0=0;

void PailaMde(void)
{
	static unsigned char estado=PAILA_OFF;

	switch (estado)
	{
		case PAILA_OFF:
			if(OnOff()==1)
			{
				Motor(ON);
				estado=PAILA_ON;
			}
			break;

		case PAILA_ON:
			if(OnOff()==1)
			{
				m_InitT0_10min();
				estado=PAILA_APAGANDOSE;
			}

			if(Parada()==1)
			{
				Motor(OFF);
				estado=PAILA_OFF;
			}
			break;

		case PAILA_APAGANDOSE:
			if(OnOff()==1)
			{
				m_StopT0();
				estado=PAILA_ON;
			}

			if(flagT0==1)
			{
				Motor(OFF);
				flagT0=0;
				estado=PAILA_OFF;
			}

			if(Parada()==1)
			{
				Motor(OFF);
				m_StopT0();
				estado=PAILA_OFF;
			}

			break;

		default:
			Motor(OFF);
			m_StopT0();
			flagT0=0;
			estado=PAILA_OFF;
	}
}

void init_PailaMde(void)
{
	Motor(OFF);
	m_StopT0();
	flagT0=0;
}
