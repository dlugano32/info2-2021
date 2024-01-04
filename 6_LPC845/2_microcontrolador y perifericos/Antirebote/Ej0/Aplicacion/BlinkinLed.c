#include "DR_Init.h"
#include "LedsMDE.h"
#include "BotonSwapMDE.h"

int main (void)
{
	InitHw();

	LED_OFF(ROJO);
	LED_OFF(VERDE);
	LED_OFF(AZUL);

	InitLedsMDE();
	InitBotonSwapMDE();

	while(1)
	{
		LedsMDE();

		if(getKey()==0)
		{
			TimerStart(2, 5, HandlerT2, SEG);
			BotonSwapMDE();
		}

		if(getKey()==1)
		{
			TimerStop(2);
		}

		TimerEvent();
	}
	return 0;
}
