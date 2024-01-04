/*
 * PR_UART.c
 *
 *  Created on: 28 oct. 2021
 *      Author: d_lugano
 */
#include "PR_UART.h"

void TxSerie0(uint8_t* buffer)
{
	uint32_t i=0;

	for(i=0; *(buffer+i)!='\0'; i++)
		PushTx0(buffer[i]);
}


int16_t RxSerie0(void)
{
	return PopRx0();
}

int16_t RxSerie1(void)
{
	//return PopRx1();
	return datoRx;
}

void TxSerie1(uint8_t* buffer)
{
	uint32_t i=0;

	for(i=0; *(buffer+i)!='\0'; i++)
		PushTx1(buffer[i]);

	flagRx=0;
	flagTx=0;
}

