/*
 * Tecla.c
 *
 *  Created on: 25 ago. 2021
 *      Author: marup
 */


#include "LPC845.h"
#include "gpio.h"
#include "Tecla.h"

uint8_t getKey(void)
{
	return GetPIN( TECLA_STICK );
}
