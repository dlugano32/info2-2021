/*
 * SprayMde.c
 *
 *  Created on: 21 jul. 2021
 *      Author: d_lugano
 */


#include "SprayMde.h"
#include "../Calefa/CalefaMde.h"
#include "../EntradasSalidas/EntradasSalidas.h"

void SprayMde(void)
{
	static unsigned char estado=SPRAY_OFF;

	switch(estado)
	{
		case SPRAY_OFF:
			if( TempIdeal() == 1 )
			{
				Pistolas(ON);
				estado=SPRAY_ON;
			}
			break;

		case SPRAY_ON:
			if(OnOff() == 1 || Parada() == 1)
			{
				Pistolas(OFF);
				estado=SPRAY_OFF;
			}
			break;

		default:
			Pistolas(OFF);
			estado=SPRAY_OFF;
	}
}

void init_SprayMde(void)
{
	Pistolas(OFF);
}
