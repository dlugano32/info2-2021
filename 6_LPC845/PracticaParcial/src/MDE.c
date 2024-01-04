/*
 * MDE.c
 *
 *  Created on: 17 nov. 2021
 *      Author: d_lugano
 */
#include "MDE.h"
#include "PR_Display.h"

uint8_t FlagT0=0;

void MdeRecepcion(uint8_t dato)
{
	static uint8_t estado=INICIO_TRAMA;

	TimerStart(0, 5, HandlerT0, SEG);	//Cada vez que entra se reinicia

	switch(estado)
	{
	case INICIO_TRAMA:
		if(dato=='#')
		{
			estado=RX_TEMP;
		}

		break;

	case RX_TEMP:

		if(dato!='#')
		{
			if(dato>60)
			{
				Display(-1);
			}
			else
			{
				Display(dato*100);	//Porque el numero tiene dos decimales
			}

			estado=INICIO_TRAMA;
		}
		break;

		default:
			estado=ESPERANDO_TRAMA;
	}
}

void HandlerT0(void)
{
	Display(-1);
}
