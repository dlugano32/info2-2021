#include "DR_Init.h"
#include "PR_UART.h"
#include "ESP8266App.h"

int main(void)
{
	InitHw();

	LED_OFF(ROJO);
	LED_OFF(VERDE);
	LED_OFF(AZUL);

    while(1)
    {
    	ESP8266_check();
    	TimerEvent();
    }
    return 0 ;
}
