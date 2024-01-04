/*
 * DR_USARTs.c
 *
 *  Created on: 17 nov. 2021
 *      Author: d_lugano
 */

#include "DR_USARTs.h"

uint8_t in_rx1=0;
uint8_t out_rx1=0;
uint8_t BufferRx1[TAM_BUFRX1];

void InitUSART1(void)
{
	SYSCON->SYSAHBCLKCTRL0|=(1<<15);	//habilito el clk de la UART1

	SYSCON->PRESETCTRL0&= ~(1<<15);		//Reseteo la UART1
	SYSCON->PRESETCTRL0|= (1<<15);

	SYSCON->SYSAHBCLKCTRL0|=(1<<7);	//Habilito el CLK de la SWM
	PINASSIGN1&=~(0x00FFFF00);
	PINASSIGN1|= ( (16<<8) | (17<<16));	//Habilito  Tx=PIO0.16 Rx=PIO0.17

	USART1->CFG= (0<<0)
				|(1<<2)
				|(3<<4)
				|(0<<6)
				|(0<<9)
				|(0<<11);

	UART1CLKSEL=0;
	USART1->BRG= CLK/(38400*16);

	USART1->INTENSET=1;	//Habilito la interrupcion por Rx de la UART1
	ISER0|=(1<<4);	//Habilito la interrupcion en el NVIC

	USART1->CFG=1;	//habilito una vez que tengo todo configurado
}

void UART1_IRQHandler(void)
{
	uint32_t aux=USART1->STAT;
	int16_t	dato;

	if(aux & (1<<0))	//Caso Rx
	{
		PushRx1(USART1->RXDAT);
	}
}

void PushRx1(uint8_t dato)
{
	BufferRx1[in_rx1]=dato;
	in_rx1++;
	in_rx1%=TAM_BUFRX1;
}

int16_t PopRx1(void)
{
	int16_t ret=-1;

	if(in_rx1!=out_rx1)	//Todavia ha datos para leer
	{
		ret=BufferRx1[out_rx1];
		out_rx1++;
		out_rx1%=TAM_BUFRX1;
	}

	return ret;
}


