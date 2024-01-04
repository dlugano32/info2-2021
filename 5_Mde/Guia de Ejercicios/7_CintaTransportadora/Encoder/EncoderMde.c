/*
 * EncoderMde.c
 *
 *  Created on: 22 jul. 2021
 *      Author: d_lugano
 */

#include "EncoderMde.h"
#include "EncoderMde_func.h"

int flagT0=0;
int velocidad=0;

static int pulse;

void EncoderMde(void)
{
	static unsigned char estado=LOW_PULSE;


	if(flagT0==1)
	{
		m_CalcularVel(pulse);
		flagT0=0;
		pulse=0;
		m_IniciarT0_1s();

	}

	switch(estado)
	{
		case LOW_PULSE:
			if(s_HayLuz())
			{
				estado=HIGH_PULSE;
			}
			break;

		case HIGH_PULSE:
			if(!s_HayLuz())
			{
				pulse++;
			}
			break;

		default:
			pulse=0;
			flagT0=0;
			velocidad=0;
			m_IniciarT0_1s;
			estado=LOW_PULSE;
	}
}

void init_EncoderMde(void)
{
	pulse=0;
	flagT0=0;
	velocidad=0;
	m_IniciarT0_1s;
}
