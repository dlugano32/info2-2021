/*
 * DR_USART.c
 *
 *  Created on: 25 nov. 2021
 *      Author: d_lugano
 */

#include "DR_USART.h"

uint8_t inTx=0;
uint8_t outTx=0;
uint8_t bufferTx[TAM];

//Uso la UART0

void UART0_IRQHandler(void)
{
	uint32_t stat=USART0->STAT;
	int16_t aux=0;

	if(stat & (1<<2))	//Caso Tx
	{
		aux=PopTx();

		if(aux!=-1)
		{
			USART0->TXDAT=aux;
		}
		else
		{
			USART0->INTENCLR|=(1<<2);	//Deshabilito la interrupcion por Tx
		}
	}
}

int16_t PopTx(void)
{
	int16_t ret=-1;

	if(inTx!=outTx)	//Hay datos para sacar;
	{
		ret=bufferTx[outTx];
		outTx++;
		outTx%=TAM;
	}

	return ret;
}

void PushTx(uint8_t dato)
{
	bufferTx[inTx]=dato;
	inTx++;
	inTx%=TAM;

	USART0->INTENSET|=(1<<2);
}
