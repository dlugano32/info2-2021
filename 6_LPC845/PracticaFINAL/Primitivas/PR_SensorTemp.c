/*
 * PR_SensorTemp.c
 *
 *  Created on: 21 nov. 2021
 *      Author: d_lugano
 */

#include "PR_SensorTemp.h"

uint32_t valADC=0;

uint32_t SensorTemp(void)
{
	uint32_t Temp=(valADC*50)/4096;
	return Temp;
}
