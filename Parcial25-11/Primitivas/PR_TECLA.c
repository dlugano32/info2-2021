/*
 * PR_TECLA.c
 *
 *  Created on: 25 nov. 2021
 *      Author: d_lugano
 */


#include "PR_TECLA.h"

uint8_t getKey(void)
{
	uint8_t aux=Tecla;
	Tecla=NO_KEY;
	return aux;
}
