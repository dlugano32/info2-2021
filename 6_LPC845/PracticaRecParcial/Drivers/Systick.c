/*
 * Systick.c
 *
 *  Created on: 19 nov. 2021
 *      Author: d_lugano
 */
#include "Systick.h"

uint8_t flag500ms=0;
uint8_t flag10seg=0;
uint8_t LedR=0;
uint8_t LedV=0;

void InitSystick(void)
{
	SYSTICK->CSR= (1<<0)
				| (1<<1)
				| (1<<2);

	SYSTICK->RVR=30000-1;
	SYSTICK->CVR=SYSTICK->RVR;
}

void SysTick_Handler(void)
{
	uint32_t aux=SYSTICK->CSR;
	static uint32_t i=0,j=0;
	static uint8_t stat_disp=0;

	BarridoTeclado();

	BarridoDisplays();


	if(flag500ms)	//Variable global
	{
		i++;
		if(i==500)
		{
			i=0;
			if(LedR)
			{
				GPIO->NOT[0]|=(1<<LR_PIN);
			}

			if(LedV)
			{
				GPIO->NOT[0]|=(1<<LV_PIN);
			}

			if(DisplayTitilando)
			{
				if(stat_disp)
				{
					SetPIN(DIG0, OFF);
					SetPIN(DIG1, OFF);
					SetPIN(DIG2, OFF);
					SetPIN(DIG3, OFF);
					SetPIN(DIG4, OFF);
					SetPIN(DIG5, OFF);
					stat_disp=0;
				}
				else
				{
					SetPIN(DIG0, ON);
					SetPIN(DIG1, ON);
					SetPIN(DIG2, ON);
					SetPIN(DIG3, ON);
					SetPIN(DIG4, ON);
					SetPIN(DIG5, ON);
					stat_disp=1;
				}
			}
		}
	}
	else
	{
		i=0;
		SetPIN(LR,OFF);
		SetPIN(LV,OFF);
	}

	if(flag10seg)
	{
		j++;
		if(j==10000)	//10000ms=10seg
		{
			flagT0=1;
			flag10seg=0;
		}
	}
	else
	{
		j=0;
	}
}

void Timer10seg(void)
{
	flag10seg=1;
}
