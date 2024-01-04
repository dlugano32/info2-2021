#include "DR_Init.h"
#include "PR_UART.h"

uint8_t MSG0[]="RECIBIDO:";
#define LONGITUD 9

int main(void)
{
	uint16_t msg;

	InitHw();

    while(1)
    {
    	msg=RecibirSerie();

    	if(msg != -1)
    	{
    		TransmitirSerie(MSG0, LONGITUD);
    		TransmitirByte(' ');
    		TransmitirByte(msg);
    		TransmitirByte('\n');
    	}
    }
    return 0 ;
}
