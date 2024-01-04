/*
 * AlarmaMde.c
 *
 *  Created on: 20 jul. 2021
 *      Author: d_lugano
 */

#include "GarageMde.h"
#include "AlarmaMde.h"
#include "AlarmaMde_func.h"

int flagT0=0;

void AlarmaMde(void)
{
	static unsigned char estado=APAGADA;

	switch(estado)
	{
		case APAGADA:

			if( HayObstruccion()==1 )
			{
				m_SirenaON();
				estado=ENCENDIDA;
			}

			break;

		case ENCENDIDA:
			if( Libre() == 1)
			{
				m_IniciarT0_10s();
				estado=APAGANDOSE;
			}

			break;

		case APAGANDOSE:

			if(flagT0==1)
			{
				flagT0=0;
				m_SirenaOff();
				estado=APAGADA;
			}
			break;

		default:
			m_SirenaOff();
			m_StopT0();
			estado=APAGADA;
	}
}

void init_AlarmaMde(void)
{
	m_SirenaOff();
	m_StopT0();
}
