/*
 * PR_USART.c
 *
 *  Created on: 17 nov. 2021
 *      Author: d_lugano
 */

#include "PR_USARTs.h"

uint8_t RecibirDatoUART1(void)
{
	return PopRx1();
}
