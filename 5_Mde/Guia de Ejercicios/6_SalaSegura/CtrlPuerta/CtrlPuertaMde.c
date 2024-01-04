/*
 * CtrlPuertaMde.c
 *
 *  Created on: 21 jul. 2021
 *      Author: d_lugano
 */

#include "CtrlPuertaMde.h"
#include "CtrlPuertaMde_func.h"

int flagT0=0;
int flagT1=0;

void CtrlPuertaMde(void)
{
	static unsigned char estado=CERRADO;

	switch(estado)
	{
		case CERRADO:
			if( s_HuellaOK() == 1 )
			{
				m_Puerta(ON);
				m_IniciarT1_10s();
				Display("Habilitado");
				m_EnviarID();
				estado=ENTRANDO;
			}

			if( s_HuellaInvalida() == 1)
			{
				m_LuzRoja(ON);
				Display("No habilitado");
				m_IniciarT0_5s();
				estado=HUELLA_ERROR;
			}
			break;

		case ENTRANDO:
			if(flagT1==1)
			{
				flagT0=0;
				m_Puerta(OFF);
				estado=PERSONA_ADENTRO;
			}
			break;

		case PERSONA_ADENTRO:
			if( s_BotonAbrir() == 1)
			{
				m_Puerta(ON);
				m_IniciarT1_10s();
				estado=SALIENDO;
			}
			break;

		case SALIENDO:
			if(flagT1==1)
			{
				flagT1=0;
				m_Puerta(OFF);
				Display("Esperando");
				estado=CERRADO;
			}
			break;

		case HUELLA_ERROR:
			if(flagT0==1)
			{
				flagT0=0;
				m_LuzRoja(OFF);
				Display("Esperando");
				estado=CERRADO;
			}
			break;

		default:
			m_Puerta(OFF);
			m_LuzRoja(OFF);
			Display("Esperando");
			flagT0=0;
			flagT1=0;
			estado=CERRADO;
	}
}

void init_CtrlPuertaMde(void)
{
	m_Puerta(OFF);
	m_LuzRoja(OFF);
	Display("Esperando");
	flagT0=0;
	flagT1=0;
}
