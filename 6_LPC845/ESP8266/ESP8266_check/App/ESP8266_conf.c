#include "DR_Init.h"
#include "PR_UART.h"
#include "ESP8266App.h"
#include "Timer.h"

#define CANT_COMANDOS 7

#define TRANSMISION 0
#define	CHECKING 1
#define LED_VERDE 2

char * comando[CANT_COMANDOS]=
{	 	 "AT\r\n"
		,"AT+CWMODE=1\r\n"
		,"AT+CWJAP=\"Fibertel WiFi982 2.4GHz\",\"0141832376\"\r\n"
		,"AT+CIPMUX=1\r\n"
		,"AT+CIPSTART=1,\"TCP\",\"192.168.0.72\",4012\r\n"
		,"AT+CIPSEND=1,10\r\n"
		,"hola mundo"
};


int main(void)
{
	static uint8_t estado = TRANSMISION;
	static uint8_t stage=0;
	uint8_t checked=0;

	//TimerStart(0, 1000, HandlerT0, MILI);

	InitHw();

	LED_ON(ROJO);
	LED_OFF(VERDE);
	LED_OFF(AZUL);

    while(1)
    {
    	TimerEvent();

    	switch(estado)
    	{
    		case TRANSMISION:

    			/*
    			if(flagT0==1)
    			{
					TxSerie1((uint8_t *)comando[stage]);
					TxSerie0((uint8_t *)comando[stage]);
					flagT0=0;
					stage++;
					estado=CHECKING;
    			}
    			*/

    			if(getKey()==PUSH)
				{
					TxSerie1((uint8_t *)comando[stage]);
					TxSerie0((uint8_t *)comando[stage]);
					stage++;
					estado=CHECKING;
				}

				break;

    		case CHECKING:
				checked=ESP8266_check();

				if(checked==0)
					estado=CHECKING;

				if(checked==1)
				{
					if(stage==CANT_COMANDOS)
						estado=LED_VERDE;
					else
					{
						estado=TRANSMISION;
						//TimerStart(0, 500, HandlerT0, MILI);
					}
				}

				break;

    		case LED_VERDE:

    			LED_ON(VERDE);
    			LED_OFF(ROJO);

    			break;
    	}
    }
    return 0 ;
}
