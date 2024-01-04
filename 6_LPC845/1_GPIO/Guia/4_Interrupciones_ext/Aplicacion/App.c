/*
 * App.c
 *
 *  Created on: 8 sep. 2021
 *      Author: d_lugano
 */

#include "DR_Init.h"
#include "MdeLeds.h"

int main(void)
{
	InitHw();
	InitMdeLeds();

	while ( 1 )
	{
		MdeLeds();
		TimerEvent();
	}

	return 0;
}
