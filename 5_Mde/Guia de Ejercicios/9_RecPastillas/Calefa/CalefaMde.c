/*
 * CalefaMde.c
 *
 *  Created on: 21 jul. 2021
 *      Author: d_lugano
 */

#include "CalefaMde.h"
#include "../EntradasSalidas/EntradasSalidas.h"

static unsigned char estado=FRIO;

void CalefaMde(void)
{
	switch(estado)
	{
		case FRIO:
			if( OnOff() == 1 )
			{
				Calefaccion(ON);
				estado=CALENTANDOSE;
			}

			break;

		case CALENTANDOSE:
			if( TempOK() == 1)
			{
				Calefaccion(OFF);
				estado=CALIENTE;
			}

			if( Parada() == 1 )
			{
				Calefaccion(OFF);
				estado=FRIO;
			}

			break;

		case CALIENTE:
			if( TempOK() == 0 )
			{
				Calefaccion(ON);
				estado=CALENTANDOSE;
			}

			if( OnOff() == 1 || Parada() == 1 )
			{
				Calefaccion(OFF);
				estado=FRIO;
			}
			break;

		default:
			Calefaccion(OFF);
			estado=FRIO;
	}
}

void init_CalefaMde(void)
{
	Calefaccion(OFF);
}

int TempIdeal (void)
{
	return (estado==CALIENTE);
}
