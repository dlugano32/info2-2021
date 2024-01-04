#include "DR_Init.h"

int main (void)
{

	InitHw();

	uint8_t Thigh=0;

	LED_ON(ROJO);
	LED_OFF(VERDE);
	LED_OFF(AZUL);

	TimerStart(0, 1, handlerT0, SEG);	//Timer para prender
	TimerStart(1, 100 , handlerT1, MILI);	//Timer para apagar


	while(1)
	{
		if(flagT1)
		{
			flagT1=0;
			LED_OFF(ROJO);
		}

		if(flagT0)
		{
			flagT0=0;
			LED_ON(ROJO);
			TimerStart(0, 1, handlerT0, SEG);	//Timer para prender
			TimerStart(1, i*100 , handlerT1, MILI);	//Timer para apagar
		}

		if(flagAscendente==1 && flagDescendente==0)
		{
			contador=0;
			flagAscendente=0;
			TimerStart(2, 1, handlerT2, MILI);
		}

		if(flagAscendente==0 && flagDescendente==1)
		{
			flagDescendente=0;
			TimerStop(2);
			Thigh=contador;
		}

		TimerEvent();
	}
}
