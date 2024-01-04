/*
 * DR_UART.c
 *
 *  Created on: 26 oct. 2021
 *      Author: d_lugano
 */

#include "DR_UART.h"
#include "../Primitivas/Leds.h"

//Variables
uint32_t in_tx1=0;
uint32_t out_tx1=0;
uint32_t in_rx1=0;
uint32_t out_rx1=0;

uint8_t buf_tx1[TAM_TX1];
uint8_t buf_rx1[TAM_RX1];

void InitUART1(void)
{
	//Habilito el clock de la UART1
	SYSCON->SYSAHBCLKCTRL0|= (1<<SYSCON_SYSAHBCLKCTRL0_UART1_SHIFT);

	//Reseteo la uart
	SYSCON->PRESETCTRL0 &= ~(1<<15);
	SYSCON->PRESETCTRL0 |= (1<<15);

	//Selecciono pines TX y RX
	SYSCON->SYSAHBCLKCTRL0|= (1<<7);	//Habilito el CLK de la SWM
	PINASSIGN1 &= ~(0x00FFFFF00); 		//Pongo en cero todos los bits
	PINASSIGN1 |= (16 << 8);
	PINASSIGN1 |= (17 << 16);	//TX=PO.16 y RX=P0.17

	//Configuracion de la comunicacion
	USART1->CFG=
		(0 << 0)	//0=DISABLE 	1=ENABLE
	|	(1 << 2)	//Data length 	0=7bits 1=8bits 2=9bits
	|	(2 << 4)	//Paridad 		0=NOPARITY 2=EVEN(PAR) 3=ODD(IMPAR)
	|	(0 << 6)	//Stop length	0=1bitStop 1=2bitStop
	|	(0 << 9)	//CTSEN			0=NOFLOWCONTROL 1=FLOWCONTROL
	|	(0 << 11)	//SYNCEN		0=ASINCRONICA 1=SINCRONICA
	;

	//Configuracion de la interrupcion por Rx
	USART1->INTENSET = (1 << 0);

	//Configuracion del baudrate
	UART1CLKSEL=0;	//CLK del periferico = FRO= 30MHz
	USART1->BRG = (FREQ_PRINCIPAL / (BAUDRATE1* 16));

	//Habilito la interrupcion USART0 en el NVIC
	ISER0 |=(1<<ISE_UART1_SHIFT);

	USART1->CFG|=1;	//Habilito la UART
}


void UART1_IRQHandler(void)
{
	uint32_t stat=USART1->STAT;
	uint8_t dato=0;

	//Caso recepcion
	if(stat & (1<<0)) // RX Ready
	{
		dato=USART1->RXDAT;
		PushRx1(dato);
	}

	if (stat & (1 << 2)) // TX Ready
	{
		dato = PopTx1();

		if ( dato != -1 )
			USART1->TXDAT = dato;
		else
			USART1->INTENCLR = 1<<2;
	}
}


void PushTx1 ( uint8_t dato)
{
	buf_tx1[in_tx1]=dato;
	in_tx1++;
	in_tx1%=TAM_TX1;

	USART1->INTENSET|= 1<<2;	//Activo las interrupciones para que me avise cuando haya terminado de mandar el mensaje para poder transmitir otra vez
}

int16_t PopTx1( void )
{
	int16_t aux=-1;

	if(in_tx1!=out_tx1)
	{
		aux=buf_tx1[out_tx1];
		out_tx1++;
		out_tx1%=TAM_TX1;
	}

	return aux;
}

void PushRx1( uint8_t dato )
{
	buf_rx1[in_rx1]=dato;
	in_rx1++;
	in_rx1%=TAM_RX1;
}

int16_t PopRx1( void )
{
	int16_t aux=-1;

	if(in_rx1!=out_rx1)
	{
		aux=buf_rx1[out_rx1];
		out_rx1++;
		out_rx1%=TAM_RX1;
	}

	return aux;
}
