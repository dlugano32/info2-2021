/*
 * BombaMde.c
 *
 *  Created on: 23 jul. 2021
 *      Author: d_lugano
 */

#include "BombaMde.h"
#include "BombaMde_func.h"

void BombaMde(void)
{
	static unsigned char estado=LLENO;

	switch(estado)
	{
	case LLENO:
		if( Sensor2() == 0)
		{
			BombaAgua(ON);
			estado=LLENANDO;
		}
		break;

	case LLENANDO:
		if( Sensor4() == 1 )
		{
			BombaAgua(OFF);
			estado=LLENO;
		}
		break;

	default:
		BombaAgua(OFF);
		estado=LLENO;
	}
}

void init_BombaMde(void)
{
	BombaAgua(OFF);
}

