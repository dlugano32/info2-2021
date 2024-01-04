/*
 * CalefaMde.c
 *
 *  Created on: 23 jul. 2021
 *      Author: d_lugano
 */


#include "CalefaMde.h"
#include "CalefaMde_func.h"
#include "BombaMde_func.h"
#include "BombaMde.h"

int flagT0=0;

void CalefaMde(void)
{
	static unsigned char estado=CALIENTE;

	switch(estado)
	{
	case CALIENTE:
		if(TempOperacion() == 0)
		{
			Calentador(ON);
			m_IniciarT0_30min();
			estado=CALENTANDO;
		}

		if(Sensor1() == 0)
		{
			Calentador(OFF);
			estado=POCA_AGUA;
		}
		break;
	case CALENTANDO:
		if(TempOperacion() == 1)
		{
			Calentador(OFF);
			m_StopT0();
			estado=CALIENTE;
		}

		if(flagT0 == 1)
		{
			Calentador(OFF);
			estado=EMERGENCIA;
		}

		if(Sensor1() == 0)
		{
			Calentador(OFF);
			estado=POCA_AGUA;
		}
		break;

	case POCA_AGUA:
		if(Sensor1() == 1)
		{
			Calentador(ON);
			estado=CALENTANDO;
		}
		break;

	case EMERGENCIA:
		if(PulsadorReset() == 1)
		{
			Calentador(ON);
			estado=CALENTANDO;
		}
		break;

	default:
		Calentador(OFF);
		m_StopT0();
		flagT0=0;
		estado=CALIENTE;
	}
}

void init_CalefaMde(void)
{
	Calentador(OFF);
	m_StopT0();
	flagT0=0;
}
