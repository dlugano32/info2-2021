#include "DR_Init.h"
#include "LedsMDE.h"
#include "BotonSwapMDE.h"

int main (void)
{
	InitHw();

	uint8_t presionado=0;

	LED_OFF(ROJO);
	LED_OFF(VERDE);
	LED_OFF(AZUL);

	InitLedsMDE();
	InitBotonSwapMDE();

	while(1)
	{
		LedsMDE();

		if(getKey()== PUSH && presionado == 0)
		{
			presionado=1;
			TimerStart(2, 5, HandlerT2, SEG);
			BotonSwapMDE();
		}

		if(getKey()==NOT_PUSH && presionado==1)
		{
			presionado=0;
			TimerStop(2);
		}

		TimerEvent();
	}
	return 0;
}
