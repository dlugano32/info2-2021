/*
 * TanqueMde.c
 *
 *  Created on: 19 jul. 2021
 *      Author: d_lugano
 */

#include "TanqueMde.h"

void TanqueMde(void)
{
	static unsigned char estado=APAGADO;

	switch(estado)
	{
		case APAGADO:
			if( s_LlaveON() )
			{
				estado=LLENO;
			}
			break;

		case LLENO:
			if( s_LlaveOff() )
			{
				estado=APAGADO;
			}

			if( s_Sensor_vacio() == 0)	//Es decir, cuando el sensor de vacio sea 0, el tanque va a estar vacio
			{
				m_BombaON();
				estado=LLENANDO;
			}

			break;

		case LLENANDO:
			if( s_LlaveOff() )
			{
				m_BombaOff();
				estado=APAGADO;
			}

			if(s_Sensor_lleno() )
			{
				m_BombaOff();
				estado=LLENO;
			}
			break;

		default:
			m_BombaOff();
			estado=APAGADO;
	}
}
