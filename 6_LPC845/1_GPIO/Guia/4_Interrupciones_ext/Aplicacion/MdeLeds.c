/*
 * MdeLeds.c
 *
 *  Created on: 13 sep. 2021
 *      Author: d_lugano
 */

#include "DR_Init.h"
#include "MdeLeds.h"

void MdeLeds(void)
{
	static uint8_t estado=ROJO;

	switch(estado)
	{
	case ROJO:
		if(flagIntExt==1 || flagT0==1)
		{
			flagIntExt=0;
			flagT0=0;
			TimerStop(0);
			TimerStart(0,1, handlerT0, SEG);
			LED_OFF(ROJO);
			LED_ON(VERDE);
			estado=VERDE;
		}

		break;

	case VERDE:
		if(flagIntExt==1 || flagT0==1)
		{
			flagIntExt=0;
			flagT0=0;
			TimerStop(0);
			TimerStart(0,1, handlerT0, SEG);
			LED_OFF(VERDE);
			LED_ON(AZUL);
			estado=AZUL;
		}
		break;

	case AZUL:
		if(flagIntExt==1 || flagT0==1)
		{
			flagIntExt=0;
			flagT0=0;
			TimerStop(0);
			TimerStart(0,1, handlerT0, SEG);
			LED_OFF(AZUL);
			LED_ON(ROJO);
			estado=ROJO;
		}
		break;
	}

}

void InitMdeLeds(void)
{
	flagT0=0;
	TimerStart(0,1, handlerT0, SEG);
	LED_ON(ROJO);
	LED_OFF(VERDE);
	LED_OFF(AZUL);
}
