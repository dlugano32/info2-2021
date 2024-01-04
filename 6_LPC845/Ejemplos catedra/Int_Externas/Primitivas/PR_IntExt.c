/*
 * PR_IntExt.c
 *
 *  Created on: 1 sep. 2021
 *      Author: marup
 */

#include "DR_IntExt.h"

uint8_t TeclaInterrupcion(void)
{
	uint8_t aux;

	aux = interrupcion;
	interrupcion = 0;
	return aux;

}
