/*
 * GarageMde.c
 *
 *  Created on: 20 jul. 2021
 *      Author: d_lugano
 */

#include "GarageMde.h"
#include "GarageMde_func.h"

static unsigned char estado=STANDBY;
static int stage;
static int n_auto;

void GarageMde(void)
{
	switch(estado)
	{
		case STANDBY:
			if( ( s_SensorEntrada() == 0) && ( s_SensorSalida()== 1 ) )
			{
				stage--;
				estado=OBST_SALIDA;
			}

			if( ( s_SensorEntrada() == 1) && ( s_SensorSalida()== 0 ) )
			{
				stage++;
				estado=OBST_ENTRADA;
			}

			break;

		case OBST_ENTRADA:
			if( ( s_SensorEntrada() == 0) && ( s_SensorSalida()== 0 ) )
			{
				if(stage==-3)
				{
					n_auto--;
				}
				stage=0;

				estado=STANDBY;
			}

			if( ( s_SensorEntrada() == 1) && ( s_SensorSalida()== 1 ) )
			{
				stage++;
				estado=OBSTRUCCION;
			}

			break;

		case OBSTRUCCION:
			if( ( s_SensorEntrada() == 1) && ( s_SensorSalida()== 0 ) )
			{
				stage--;
				estado=OBST_ENTRADA;
			}

			if( ( s_SensorEntrada() == 0) && ( s_SensorSalida()== 1 ) )
			{
				stage++;
				estado=OBST_SALIDA;
			}

			break;

		case OBST_SALIDA:

			if( ( s_SensorEntrada() == 1) && ( s_SensorSalida()== 1 ) )
			{
				stage--;
				estado=OBSTRUCCION;
			}

			if( ( s_SensorEntrada() == 0) && ( s_SensorSalida()== 0 ) )
			{
				if(stage == 3)
				{
					n_auto++;
				}
				stage=0;
				estado=STANDBY;
			}

			break;

		default:
			stage=0;
			estado=STANDBY;
	}
}

void init_GarageMde(void)
{
	n_auto=0;
	stage=0;
}

int HayObstruccion(void)
{
	return ( estado == OBSTRUCCION );
}

int Libre(void)
{
	return (estado == STANDBY);
}
