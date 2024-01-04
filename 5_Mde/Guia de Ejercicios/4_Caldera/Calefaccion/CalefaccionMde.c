/*
 * CalefaccionMde.c
 *
 *  Created on: 20 jul. 2021
 *      Author: d_lugano
 */

#include "TanqueMde.h"
#include "CalefaccionMde.h"
#include "CalefaccionMde_func.h"

void CalefaccionMde(void)
{
	static unsigned char estado=VACIO;

	switch(estado)
	{
		case VACIO:

			if( HayAgua() && TempLow() )
			{
				m_CalentadorON();
				estado=CALENTANDO;
			}
			break;

		case CALENTANDO:
			if( HayAgua() == 0)
			{
				m_CalentadorOff();
			}

			if( TempOk() )
			{
				m_CalentadorOff();
				estado=CALIENTE;
			}

			break;

		case CALIENTE:
			if( TempLow())
			{
				m_CalentadorON();
				estado=CALENTANDO;
			}

			if( HayAgua() == 0)
			{
				m_CalentadorOff();
				estado=VACIO;
			}
			break;

		default:
			m_CalentadorOff();
			estado=VACIO;
	}
}

void init_CalefaccionMde(void)
{
	m_CalentadorOff();
}

