/*
 * CalefaccionMde.c
 *
 *  Created on: 19 jul. 2021
 *      Author: d_lugano
 */

#include "CalefaccionMde.h"

void calefaccionMde (void)
{
	static unsigned char estado=STAND_BY;

	switch(estado)
	{
		case STAND_BY:
			if(s_Boton())
			{
				m_calentadorOff();
				estado=APAGADO;
			}
			break;

		case ENCENDIDO:
			if(s_boton())
			{
				m_calentadorOff();
				estado=STAND_BY;
			}

			if( getTemperatura() >= TEMP_FINAL )
			{
				m_calentadorOff();
				estado=APAGADO;
			}
			break;

		case APAGADO:
			if(s_Boton())
			{
				m_CalentadorOff();
				estado=STAND_BY;
			}

			if( getTemperatura() <= (TEMP_FINAL - BANDA_HISTERESIS) )
			{
				m_CalentadorON();
				estado=ENCENDIDO;
			}
			break;

		default:
			m_CalentadorOff();
			estado=STAND_BY;
	}
}
