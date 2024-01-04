/*
 * BotonSwapMDE.c
 *
 *  Created on: 9 sep. 2021
 *      Author: d_lugano
 */

#include "DR_Init.h"
#include "BotonSwapMDE.h"
#include "LedsMDE.h"

static uint8_t flagON;

void BotonSwapMDE(void)
{
	static uint8_t estado=ROJO;

	switch(estado)
	{
		case ROJO:
				if( ReadLed(colorLed)==0 )
				{
					LED_OFF(colorLed);
					flagON=1;
				}

				colorLed=VERDE;

				if(flagON)
				{
					LED_ON(colorLed);
					flagON=0;
				}

				estado=VERDE;
			break;

		case VERDE:
			if( ReadLed(colorLed)==0 )
			{
				LED_OFF(colorLed);
				flagON=1;
			}

			colorLed=AZUL;

			if(flagON)
			{
				LED_ON(colorLed);
				flagON=0;
			}

			estado=AZUL;

			break;

		case AZUL:
			if( ReadLed(colorLed)==0 )
			{
				LED_OFF(colorLed);
				flagON=1;
			}

			colorLed=ROJO;

			if(flagON)
			{
				LED_ON(colorLed);
				flagON=0;
			}

			estado=ROJO;
			break;
	}
}

void InitBotonSwapMDE(void)
{
	flagON=0;
}
