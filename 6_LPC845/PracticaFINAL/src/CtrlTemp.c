/*
 * CtrlTemp.c
 *
 *  Created on: 21 nov. 2021
 *      Author: d_lugano
 */

#include "CtrlTemp.h"
#include "PR_SensorTemp.h"

void CtrlTemp(void)
{
	static uint8_t estado=LEER_SENSOR;
	uint32_t temp;

	switch(estado)
	{
	case LEER_SENSOR:
		temp=SensorTemp();
		break;
	}
}
