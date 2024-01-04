/*
 * CtrlSalaMde.c
 *
 *  Created on: 22 jul. 2021
 *      Author: d_lugano
 */

#include "CtrlSalaMde.h"
#include "CtrlSalaMde_func.h"

int dato=0;

static unsigned char salida=0;

void CtrlSalaMde(void)
{
	static unsigned char estado=REPOSO;

	switch(estado)
	{
		case REPOSO:
			if(verificacion!=1)
			{
				dato=PopRx();

				if( dato != 0xFF )
				{
					CtrlAccesoMde();
				}

				estado=REPOSO;
			}

			if(verificacion==1)
			{
				m_Puerta(ON);
				m_IniciarT1_2s();
				m_IniciarT2_30min();
				estado=ABIERTO;
			}
			break;

		case ABIERTO:
			if(flagT1==1 && salida==0)
			{
				m_Puerta(OFF);
				flagT1=0;
				estado=CERRADO_P;
			}

			if(flagT1==1 && salida==1)
			{
				m_Puerta(OFF);
				salida=0;
				flagT1=0;
				init_CtrlAccesoMde();
				estado=REPOSO;
			}
			break;

		case CERRADO_P:
			if(s_Boton1())
			{
				m_Puerta(ON);
				m_StopT2();
				m_IniciarT1_2s();
				salida=1;
			}
			if(flagT2==1)
			{
				m_Alarma(ON);
				m_LuzRoja(ON);
				flagT2=0;
				estado=ALARMA_TIEMPO;
			}

			if( Temperatura() > TEMP_MAX )
			{
				m_Alarma(ON);
				m_LuzAzul(ON);
				m_StopT2();
				estado=ALARMA_TEMP;
			}
			break;

		case ALARMA_TIEMPO:
			if(s_Boton2())
			{
				m_Alarma(OFF);
				m_LuzRoja(OFF);
				m_IniciarT3_2min();
				estado=TIEMPO_EXTENDIDO;
			}
			break;

		case ALARMA_TEMP:
			if(s_Boton2())
			{
				m_Alarma(OFF);
				m_LuzAzul(OFF);
				m_IniciarT3_2min();
				estado=TIEMPO_EXTENDIDO;
			}
			break;

		case TIEMPO_EXTENDIDO:
			if(flagT3==1)
			{
				m_alarmaSupervisor();
				flagT3=0;
				estado=ALARMA_SUPERVISOR;
			}

			if(s_Boton1())
			{
				m_Puerta(ON);
				m_StopT3();
				m_IniciarT1_2s();
				salida=1;
				estado=ABIERTO;
			}
			break;

		case ALARMA_SUPERVISOR:
			//codigo del cual no nos encargamos
			break;

		default:
			init_CtrlAccesoMde();
			m_Puerta(OFF);
			m_Alarma(OFF);
			m_LuzRoja(OFF);
			m_LuzAzul(OFF);
			m_StopT1();
			m_StopT2();
			m_StopT3();
			flagT1=0;
			flagT2=0;
			flagT3=0;
			salida=0;
			estado=REPOSO;
	}
}

void init_CtrlSalaMde(void)
{
	init_CtrlAccesoMde();
	m_Puerta(OFF);
	m_Alarma(OFF);
	m_LuzRoja(OFF);
	m_LuzAzul(OFF);
	m_StopT1();
	m_StopT2();
	m_StopT3();
	flagT1=0;
	flagT2=0;
	flagT3=0;
	salida=0;
}

