/*
 * DR_UART.c
 *
 *  Created on: 26 oct. 2021
 *      Author: d_lugano
 */

#include "DR_UART.h"

void InitUART0(void)
{
	//Habilito el clock de la UART0
	SYSCON->SYSAHBCLKCTRL0|= (1<<SYSCON_SYSAHBCLKCTRL0_UART0_SHIFT);

	//Reseteo la uart
	SYSCON->PRESETCTRL0 &= ~(1<<14);
	SYSCON->PRESETCTRL0 |= (1<<14);

	//Selecciono pines TX y RX
	SYSCON->SYSAHBCLKCTRL0|= (1<<7);	//Habilito el CLK de la SWM
	PINASSIGN0 &= ~(0x0000FFFFF); 		//Pongo en cero todos los bits
	PINASSIGN0 = (25 << 0) | (24 << 8);	//TX=PO.25 y RX=P0.24

	//Configuracion de la comunicacion
	USART0->CFG=
		(0 << 0)	//0=DISABLE 	1=ENABLE
	|	(1 << 2)	//Data length 	0=7bits 1=8bits 2=9bits
	|	(0 << 4)	//Paridad 		0=NOPARITY 2=EVEN(PAR) 3=ODD(IMPAR)
	|	(0 << 6)	//Stop length	0=1bitStop 1=2bitStop
	|	(0 << 9)	//CTSEN			0=NOFLOWCONTROL 1=FLOWCONTROL
	|	(0 << 11)	//SYNCEN		0=ASINCRONICA 1=SINCRONICA
	;

	//Configuracion de la interrupcion
	USART0->INTENSET = (1 << 0);	//RX

	//Configuracion del baudrate
	UART0CLKSEL=0;	//CLK del periferico = FRO= 30MHz
	USART0->BRG = (FREQ_PRINCIPAL / (BAUDRATE* 16));

	//Habilito la interrupcion USART0 en el NVIC
	ISER0 |=(1<<ISE_UART0_SHIFT);

	USART0->CFG|=1;	//Habilito la UART
}

void UART0_IRQHandler (void)
{
	uint32_t stat = USART0->STAT;

    // CASO RECEPCION
	if(stat & (1 << 0))
	{
	}

	//CASO TRANSMISION
	if(stat & (1 << 2))
	{
	}

	//CASO ERRORES
	else
	{

	}

}
