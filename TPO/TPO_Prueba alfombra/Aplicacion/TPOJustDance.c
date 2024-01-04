/*
===============================================================================
 Name        : TPOJustDance.c
 Author      : dlugano
 Date		 : 21/9/2021
===============================================================================
*/

#include "DR_Init.h"

struct Cancion
{
	uint8_t timestap;
	uint8_t tecla;
};


int main (void)
{
	uint8_t key=0;

	static uint8_t led=1;

	InitHw();

	LED_OFF(ROJO);
	LED_OFF(VERDE);
	LED_OFF(AZUL);

	while(1)
	{
		key=getKey();

		switch(key)
		{
		case SELECT:
			if(led==0)
			{
				LED_ON(ROJO);
				led=1;
			}
			else if(led==1)
			{
				LED_OFF(ROJO);
				led=0;
			}
			break;

		case CRUZ:
			if(led==0)
			{
				LED_ON(ROJO);
				led=1;
			}
			else if(led==1)
			{
				LED_OFF(ROJO);
				led=0;
			}
			break;

		case LEFT_ARROW:
			if(led==0)
			{
				LED_ON(ROJO);
				led=1;
			}
			else if(led==1)
			{
				LED_OFF(ROJO);
				led=0;
			}
			break;

		case TRIANGLE:
			if(led==0)
			{
				LED_ON(ROJO);
				led=1;
			}
			else if(led==1)
			{
				LED_OFF(ROJO);
				led=0;
			}
			break;

		case DOWN_ARROW:
			if(led==0)
			{
				LED_ON(ROJO);
				led=1;
			}
			else if(led==1)
			{
				LED_OFF(ROJO);
				led=0;
			}
			break;

		case UP_ARROW:
			if(led==0)
			{
				LED_ON(ROJO);
				led=1;
			}
			else if(led==1)
			{
				LED_OFF(ROJO);
				led=0;
			}
			break;

		case SQUARE:
			if(led==0)
			{
				LED_ON(ROJO);
				led=1;
			}
			else if(led==1)
			{
				LED_OFF(ROJO);
				led=0;
			}
			break;

		case RIGTH_ARROW:
			if(led==0)
			{
				LED_ON(ROJO);
				led=1;
			}
			else if(led==1)
			{
				LED_OFF(ROJO);
				led=0;
			}
			break;

		case CIRCLE:
			if(led==0)
			{
				LED_ON(ROJO);
				led=1;
			}
			else if(led==1)
			{
				LED_OFF(ROJO);
				led=0;
			}
			break;

		case START:
			if(led==0)
			{
				LED_ON(ROJO);
				led=1;
			}
			else if(led==1)
			{
				LED_OFF(ROJO);
				led=0;
			}
			break;

		default:
			key=NO_KEY;
		}

		TimerEvent();
	}
	return 0;
}
