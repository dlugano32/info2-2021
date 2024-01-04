/*
 * AlarmaMde.c
 *
 *  Created on: 15 jul. 2021
 *      Author: d_lugano
 */

#include "AlarmaMde.h"
#include "AlarmaMde_funciones.h"

int flag_T1=0;

void AlarmaMde(void)
{
	static unsigned char estado=SIRENA_OFF;

	switch (estado)
	{
		case SIRENA_OFF:
						if(flag_T1 == 1)
						{
							flag_T1=0;
							m_Sirena_on();
							m_Iniciar_T1_0_5s();
							estado=SIRENA_ON;
						}
			break;

		case SIRENA_ON:
						if(flag_T1 == 1)
						{
							flag_T1=0;
							m_Sirena_off();
							m_Iniciar_T1_0_5s();
							estado=SIRENA_OFF;
						}
			break;


		default:
				m_Stop_T1();
				m_Sirena_off();
				estado=SIRENA_OFF;
	}
}

void init_AlarmaMde(void)
{
	m_Sirena_off();
	flag_T1=0;
	m_Iniciar_T1_0_5seg();
}
