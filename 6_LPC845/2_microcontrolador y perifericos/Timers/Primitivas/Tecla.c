/*
 * Tecla.c
 *
 *  Created on: 26 ago. 2021
 *      Author: d_lugano
 */

#include "Tecla.h"

uint8_t Tecla=NOT_PUSH;

uint32_t getKey(void)		//Uso los switchs por nivel y no por flanco
{
	uint32_t ret=Tecla;
	return ret;
}
