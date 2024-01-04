/*
 * PR_Teclado.c
 *
 *  Created on: 19 nov. 2021
 *      Author: d_lugano
 */
#include "PR_Teclado.c"

uint8_t getKey(void)
{
	uint8_t aux=Tecla;
	Tecla=NO_KEY;
	return aux;
}
