/*
 * AlarmaMde.c
 *
 *  Created on: 22 jul. 2021
 *      Author: d_lugano
 */

#include "AlarmaMde.h"
#include "AlarmaMde_func.h"

int flagT0=0;

void AlarmaMde(void)
{
	static unsigned char estado=ARMADO;

	switch(estado)
	{
		case ARMADO:
			if(s_Barrera())
			{
				m_AlarmaSilenciosa(ON);
				m_IniciarT0_10s();
				estado=ALARMA_SILENCIOSA;
			}

			if(s_Peso()>20)
			{
				m_AlarmaSonora(ON);
				m_Camara(ON);
				estado=ALARMA_SONORA;
			}

			break;

		case ALARMA_SONORA:
			if(s_PulsadorExt())
			{
				m_AlarmaSonora(OFF);
				m_AlarmaSilenciosa(OFF);
				m_Camara(OFF);
				estado=ARMADO;
			}
			break;

		case ALARMA_SILENCIOSA:
			if(flagT0==1)
			{
				m_AlarmaSonora(ON);
				flagT0=0;
				estado=ALARMA_SONORA;
			}

			if(s_Peso()>20)
			{
				m_AlarmaSonora(ON);
				m_Camara(ON);
				estado=ALARMA_SONORA;
			}

			if(s_PulsadorExt())
			{
				m_AlarmaSilenciosa(OFF);
				m_StopT0();
				estado=ARMADO;
			}
			break;

		default:
			m_AlarmaSilenciosa(OFF);
			m_AlarmaSonora(OFF);
			m_Camara(OFF);
			m_StopT0();
			flagT0=0;
			estado=ARMADO;
	}
}

void init_AlarmaMde(void)
{
	m_AlarmaSilenciosa(OFF);
	m_AlarmaSonora(OFF);
	m_Camara(OFF);
	m_StopT0();
	flagT0=0;
}
