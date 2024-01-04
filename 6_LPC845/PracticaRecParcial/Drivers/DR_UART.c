/*
 * UART.c
 *
 *  Created on: 19 nov. 2021
 *      Author: d_lugano
 */

#include "DR_UART.h"

uint8_t indiceTx_in =0;
uint8_t indiceTx_out =0;
uint8_t indiceRx_in =0;
uint8_t indiceRx_out =0;

void InitUART1(void)
{
	SYSCON->SYSAHBCLKCTRL0|=(1<<15);	//Habilito el periferico de la UART1

	SYSCON->PRESETCTRL0&=~(1<<15);	//Reseteo el periferico
	SYSCON->PRESETCTRL0|=(1<<15);

	SYSCON->SYSAHBCLKCTRL0|=(1<<7);	//Habilito la SWM
	PINASSIGN1&= ~(0x00FFFF00);
	PINASSIGN1|=( (22<<8) | (23<<16) );	//Tx=PIO0.22	Rx=PIO0.23

	USART1->CFG= (0<<1)
				|(1<<2)
				|(0<<4)
				|(0<<6)
				|(0<<9)
				|(0<<11);

	UART1CLKSEL=0;
	USART1->BRG= 30000000/(4800 *16);

	USART1->INTENSET|=(1<<0);
	ISER0|=(1<<4);

	USART1->CFG|=1;	//Habilito el periferico
}

void UART1_IRQHandler(void)
{
	uint32_t stat=USART1->STAT;
	uint8_t aux;

	if( stat & 1 )	//Caso Rx
	{
		PushRx(USART1->RXDAT);
	}

	if( stat & (1<<2) ) //Caso Tx
	{
		aux=PopTx();

		if(aux!=-1)
		{
			USART1->TXDAT=aux;
		}
		else
		{
			USART1->INTENCLR|=(1<<2);	//Deshabilito las interrupciones por TX
		}
	}

}

void PushRx(uint8_t dato)
{
	bufferRx[indiceRx_in];
	indiceRx_in++;
	indiceRx_in%=TAM;
}

uint8_t PopRx(void)
{
	uint8_t ret=-1;

	if(indiceRx_in!=indiceRx_out)	//Todavia hay cosas para sacar
	{
		ret=bufferTx[indiceRx_out];
		indiceRx_out++;
		indiceRx_out&=TAM;
	}

	return ret;
}

uint8_t PopTx(void)
{
	uint8_t ret=-1;

	if(indiceTx_in!=indiceTx_out)	//Todavia hay cosas para sacar
	{
		ret=bufferTx[indiceTx_out];
		indiceTx_out++;
		indiceTx_out&=TAM;
	}

	return ret;
}

void PushTx(uint8_t dato)
{
	bufferTx[indiceTx_in];
	indiceTx_in++;
	indiceTx_in%=TAM;

	USART1->INTENSET|=(1<<2);	//Activo la interrupcion por Tx
}


