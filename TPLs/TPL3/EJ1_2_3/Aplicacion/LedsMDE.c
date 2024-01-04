/*
 * LedsMDE.c
 *
 *  Created on: 9 sep. 2021
 *      Author: d_lugano
 */

#include "DR_Init.h"
#include "LedsMDE.h"

uint8_t colorLed=ROJO;
uint8_t presionado=0;

void LedsMDE(void)
{
	static uint8_t estado=F0_25;


	if(flagT2 == 1)
	{
		flagT2=0;
		presionado =1;
		estado=APAGADO;
	}

	switch(estado)
	{
		case F0_25:
			if(flagT1==1)
			{
				flagT1=0;
				SwapEstadoLed(colorLed);
				TimerStart(1, 4, HandlerT1, SEG);
				estado=F0_25;
			}

			if(flagT0==1)
			{
				flagT0=0;
				TimerStop(1);
				LED_ON(colorLed);
				TimerStart(1, 2, HandlerT1, SEG);
				TimerStart(0, 10, HandlerT0, SEG);
				estado=F0_5;
			}

			break;

		case F0_5:
			if(flagT1==1)
			{
				flagT1=0;
				SwapEstadoLed(colorLed);
				TimerStart(1, 2, HandlerT1, SEG);
				estado=F0_5;
			}

			if(flagT0==1)
			{
				flagT0=0;
				TimerStop(1);
				LED_ON(colorLed);
				TimerStart(1, 1, HandlerT1, SEG);
				TimerStart(0, 10, HandlerT0, SEG);
				estado=F1;
			}

			break;

		case F1:
			if(flagT1==1)
			{
				flagT1=0;
				SwapEstadoLed(colorLed);
				TimerStart(1, 1, HandlerT1, SEG);
				estado=F1;
			}

			if(flagT0==1)
			{
				flagT0=0;
				TimerStop(1);
				LED_ON(colorLed);
				TimerStart(1, 500 , HandlerT1, MILI);
				TimerStart(0, 10, HandlerT0, SEG);
				estado=F2;
			}
			break;

		case F2:
			if(flagT1==1)
			{
				flagT1=0;
				SwapEstadoLed(colorLed);
				TimerStart(1, 500, HandlerT1, MILI);
				estado=F2;
			}

			if(flagT0==1)
			{
				flagT0=0;
				TimerStop(1);
				LED_ON(colorLed);
				TimerStart(1, 4, HandlerT1, SEG);
				TimerStart(0, 10, HandlerT0, SEG);
				estado=F0_25;
			}
			break;

		case APAGADO:

			LED_OFF(ROJO);
			LED_OFF(VERDE);
			LED_OFF(AZUL);

			if(getKey()==0 && presionado==0)
			{
				estado=F0_25;
			}

			if(getKey()==1)
				presionado=0;

			break;

		default:
			TimerStart(0, 10, HandlerT0, SEG);
			TimerStart(1, 4, HandlerT1, SEG);
			LED_ON(colorLed);
			flagT0=0;
			flagT1=0;
			estado=F0_25;
	}
}

void InitLedsMDE(void)
{
	flagT0=0;
	flagT1=0;
	presionado=0;
	TimerStart(0, 10, HandlerT0, SEG);
	TimerStart(1, 4, HandlerT1, SEG);
	LED_ON(colorLed);
}
