/*
 * LedMde.c
 *
 *  Created on: 19 jul. 2021
 *      Author: d_lugano
 */

#include "LedMde.h"

void LedMde(void)
{
	static unsigned char estado=PAUSA;

	switch(estado)
	{
		case PAUSA:
			if(s_Boton() && flag_Led==1)
			{
				m_LedON();
				m_iniciarT0();
				estado=LED_ON;
			}

			if(s_Boton() && flag_Led==0)
			{
				m_LedOff();
				m_iniciarT0();
				estado=LED_OFF;
			}

			break;

		case LED_ON:
			if(s_Boton)
			{
				n_LedON();
				m_StopT0();
				estado=PAUSA;
			}

			if(flagT0==1)
			{
				m_LedOff();
				m_iniciarT0();
				flagT0=0;
				flag_Led=0;
				estado=LED_OFF;
			}

			break;

		case LED_OFF:

			if(s_Boton)
			{
				n_LedOff();
				m_StopT0();
				estado=PAUSA;
			}

			if(flagT0==1)
			{
				m_LedON();
				m_iniciarT0();
				flagT0=0;
				flag_Led=1;
				estado=LED_ON;
			}

			break;

		default:
			m_LedOff();
			flag_Led=1;
			flagT0=0;
			m_StopT0;
			estado=PAUSA;
	}
}
