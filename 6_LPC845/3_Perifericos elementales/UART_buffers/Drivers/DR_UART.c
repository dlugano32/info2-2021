/*
 * DR_UART.c
 *
 *  Created on: 26 oct. 2021
 *      Author: d_lugano
 */

#include "DR_UART.h"

//Variables
uint32_t in_tx=0;
uint32_t out_tx=0;
uint32_t in_rx=0;
uint32_t out_rx=0;

uint8_t buf_tx[TAM_TX];
uint8_t buf_rx[TAM_RX];


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
	int32_t aux;

    // CASO RECEPCION
	if(stat & (1 << 0))
	{
		PushRx(USART0->RXDAT);
	}

	//CASO TRANSMISION
	if(stat & (1 << 2))
	{
		aux=PopTx();

		if(aux!=-1)
			USART0->TXDAT=aux;
		else
			USART0->INTENCLR=1<<2;	//Desactivo las interrupciones por Tx para avisar cuando se termino de mandar
	}

	//CASO ERRORES
	else
	{

	}

}

void PushRx( uint8_t dato )
{
	buf_rx[in_rx]=dato;
	in_rx++;
	in_rx%=TAM_RX;
}

int16_t PopRx( void )
{
	int16_t aux=-1;

	if(in_rx!=out_rx)
	{
		aux=buf_rx[out_rx];
		out_rx++;
		out_rx%=TAM_RX;
	}

	return aux;
}

void PushTx ( uint8_t dato)
{
	buf_tx[in_tx]=dato;
	in_tx++;
	in_tx%=TAM_TX;

	USART0->INTENSET|= 1<<2;	//Activo las interrupciones para que me avise cuando haya terminado de mandar el mensaje para poder transmitir otra vez
}

int16_t PopTx( void )
{
	int16_t aux=-1;

	if(in_tx!=out_tx)
	{
		aux=buf_tx[out_tx];
		out_tx++;
		out_tx%=TAM_TX;
	}

	return aux;
}
