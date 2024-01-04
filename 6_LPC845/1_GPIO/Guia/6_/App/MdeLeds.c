/*
 * MdeLeds.c
 *
 *  Created on: 13 sep. 2021
 *      Author: d_lugano
 */

#include "DR_Init.h"
#include "MdeLeds.h"

static uint8_t red=0;
static uint8_t green=0;
static uint8_t blue=0;

void MdeLeds(void)
{
	static uint8_t estado=ROJO;



	switch(estado)
	{
	case ROJO:
		if(flagIntExt==1)
		{
			flagIntExt=0;
			TimerStop(0);
			red=1;
			green=0;
			blue=0;
			flagT0=0;
			estado=STAND_BY;
		}

		if(flagT0)
		{
			flagT0=0;
			TimerStart(0,1,handlerT0,SEG);
			LED_OFF(ROJO);
			LED_ON(VERDE);
			estado=VERDE;
		}

		break;

	case VERDE:
		if(flagIntExt==1)
		{
			flagIntExt=0;
			TimerStop(0);
			red=0;
			green=1;
			blue=0;
			flagT0=0;
			estado=STAND_BY;
		}

		if(flagT0)
		{
			flagT0=0;
			TimerStart(0,1,handlerT0,SEG);
			LED_OFF(VERDE);
			LED_ON(AZUL);
			estado=AZUL;
		}
		break;

	case AZUL:
		if(flagIntExt==1)
		{
			flagIntExt=0;
			TimerStop(0);
			red=0;
			green=0;
			blue=1;
			flagT0=0;
			estado=STAND_BY;
		}

		if(flagT0)
		{
			flagT0=0;
			TimerStart(0,1,handlerT0,SEG);
			LED_OFF(AZUL);
			LED_ON(ROJO);
			estado=ROJO;
		}
		break;

	case STAND_BY:
		if(red==1 && flagIntExt==1)
		{
			flagIntExt=0;
			flagT0=0;
			TimerStart(0,1,handlerT0,SEG);
			estado=ROJO;
		}

		if(green==1 && flagIntExt==1)
		{
			flagIntExt=0;
			flagT0=0;
			TimerStart(0,1,handlerT0,SEG);
			estado=VERDE;
		}

		if(blue==1 && flagIntExt==1)
		{
			flagIntExt=0;
			flagT0=0;
			TimerStart(0,1,handlerT0,SEG);
			estado=AZUL;
		}

		break;
	}

}

void InitMdeLeds(void)
{
	TimerStart(0,1,handlerT0,SEG);
	LED_ON(ROJO);
	LED_OFF(AZUL);
	LED_OFF(VERDE);
	red=1;
	blue=0;
	green=0;
	flagT0=0;
}
