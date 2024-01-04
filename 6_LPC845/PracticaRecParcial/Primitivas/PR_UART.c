/*
 * PR_UART.c
 *
 *  Created on: 19 nov. 2021
 *      Author: d_lugano
 */
#include "PR_UART.h"

uint8_t RxLGT(void)
{
	return PopRx();
}

void TxLGT(uint8_t *buffer)
{
	uint8_t i=0;

	for(i=0; *(buffer +i)!='\0'; i++)
	{
		PushTx(buffer[i]);
	}
}
