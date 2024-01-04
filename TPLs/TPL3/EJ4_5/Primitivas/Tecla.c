/*
 * Tecla.c
 *
 *  Created on: 26 ago. 2021
 *      Author: d_lugano
 */

#include "Tecla.h"
#include "gpio.h"
#include "LPC845.h"

uint32_t getKey(void)
{
	uint32_t ret=0;

	ret = GetPIN(BOTON_STICK);

	return ret;
}
