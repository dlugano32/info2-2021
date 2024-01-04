#include "App.h"
#include "LPC845.h"
#include "Leds.h"
#include "DR_Init.h"
#include "gpio.h"

unsigned char flag_systick=0;

int main(void)
{
	InitHw();

    LED_OFF(ROJO);
    LED_OFF(VERDE);
    LED_OFF(AZUL);

    while(1)
    {
    	if(flag_systick==1)
    	{
    		if( GetPIN(1,2)== 0 )
    			LED_OFF(ROJO);
    		else
    			LED_ON(ROJO);

    		flag_systick=0;
    	}
    }
}


