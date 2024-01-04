/*
 * PR_USART.c
 *
 *  Created on: 25 nov. 2021
 *      Author: d_lugano
 */


#include "PR_USART.h"

void TxSerie(uint8_t * buffer)
{
	uint8_t i=0;

	for(i=0; *(buffer+i)!='\0'; i++)
	{
		PushTx(*(buffer+i));
	}
}

void EnviarTrama(uint32_t dato)
{
	uint8_t buffer[6];

	buffer[0]='#';
	buffer[1]= (dato>>24) & 0xFF;
	buffer[2]= (dato>>16) & 0xFF;
	buffer[3]= (dato>>8) & 0xFF;
	buffer[4]= dato & 0xFF;
	buffer[5]='\0';		//No se manda, es solo para que TxSerie() sepa donde termina el string
	TxSerie(buffer);
}
