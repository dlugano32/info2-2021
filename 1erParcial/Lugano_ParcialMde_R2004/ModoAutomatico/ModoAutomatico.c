/*
 * ModoAutomatico.c
 *
 *  Created on: 24 jul. 2021
 *      Author: d_lugano
 */

#include "ModoAutomatico.h"
#include "ModoAutomatico_func.h"

//Variables extern
int flagTPA=0;
int	flagT1=0;

//Variables globales a este archivo
static unsigned char retry_abrir=0;
static unsigned char retry_cerrar=0;

void ModAutMde(void)
{
	static unsigned char estado =ABIERTO;

	switch (estado)
	{
		case ABIERTO:
			if( ( flagTPA==1 || s_BotonCerrar() == 0) && ( s_Barrera() == 0 && s_BotonAbrir()==1 ) )
			{
				m_MotorCerrarPuerta(ON);
				m_IniciarT1_10seg();
				flagTPA=0;
				m_StopT0();
				estado=CERRANDO;
			}
			break;

		case CERRANDO:
			if(s_PuertaCerrada() == 0)
			{
				m_MotorCerrarPuerta(OFF);
				retry_cerrar=0;
				estado=CERRADO;
			}

			if(flagT1 == 1 && retry_cerrar == 0)
			{
				m_MotorCerrarPuerta(OFF);
				m_MotorAbrirPuerta(ON);
				retry_cerrar=1;
				flagT1=0;
				estado=ABRIENDO;
			}

			if(s_Barrera()==1 || s_BotonAbrir()==0)
			{
				m_MotorCerrarPuerta(OFF);
				m_MotorAbrirPuerta(ON);
				m_IniciarT1_10seg();
				estado=ABRIENDO;
			}

			if(flagT1 == 1 && retry_cerrar == 1)
			{
				m_MotorCerrarPuerta(OFF);
				estado=FALLA;
			}

			break;

		case CERRADO:
			if (s_LlegoPiso()==0 || retry_abrir == 1)
			{
				m_MotorAbrirPuerta(ON);
				m_IniciarT1_10seg();
				estado=ABRIENDO;
			}
			break;

		case ABRIENDO:
			if(s_PuertaAbierta() == 0)
			{
				m_MotorAbrirPuerta(OFF);
				m_IniciarT0_TPAseg();
				m_StopT1();
				retry_abrir=0;
				estado=ABIERTO;
			}

			if(flagT1 == 1 && retry_abrir == 0)
			{
				m_MotorAbrirPuerta(OFF);
				m_MotorCerrarPuerta(ON);
				retry_abrir=1;
				flagT1=0;
				estado=CERRANDO;
			}

			if(flagT1 == 1 && retry_abrir == 1)
			{
				m_MotorAbrirPuerta(OFF);
				estado=FALLA;
			}
			break;

		case FALLA:
			//Espero al boton de reset
			break;

		default:
			m_MotorAbrirPuerta(OFF);
			m_MotorCerrarPuerta(OFF);
			m_StopT0();
			m_StopT1();
			flagTPA=0;
			flagT1=0;
			retry_abrir=0;
			retry_cerrar=0;
			m_IniciarT0_TPAseg();
			estado=ABIERTO;
	}
}

void init_ModAutMde(void)
{
	m_MotorAbrirPuerta(OFF);
	m_MotorCerrarPuerta(OFF);
	m_StopT0();
	m_StopT1();
	flagTPA=0;
	flagT1=0;
	retry_abrir=0;
	retry_cerrar=0;
	m_IniciarT0_TPAseg();
}
