#include "LPC845.h"
#include "DR_Init.h"
#include "gpio.h"
#include "Leds.h"
#include "Tecla.h"

int main(void)
{
	InitHw();

    uint8_t presionada = 0 ;
    uint8_t led_prendido = 0;

    LED_OFF(ROJO);
    LED_OFF(VERDE);
    LED_OFF(AZUL);

    while(1)
    {
        if( !getKey() && !presionada )
        {
        	if( led_prendido )
        	{
        		led_prendido = 0;
        		LED_OFF(ROJO);
        	}
        	else
        	{
        		led_prendido = 1;
        		LED_ON(ROJO);
        	}
        	presionada = 1;
        }
        else if( getKey() )
        {
        	presionada = 0;
        }
    }
    return 0 ;
}
