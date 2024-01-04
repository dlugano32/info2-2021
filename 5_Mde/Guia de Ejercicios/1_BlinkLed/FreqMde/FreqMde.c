/*
 * FreqMde.c
 *
 *  Created on: 19 jul. 2021
 *      Author: d_lugano
 */

#include "FreqMde.h"

int time;

void FreqMde(void)
{
	static unsigned char estado=HIGH_FREQ;

	switch(estado)
	{
		case HIGH_FREQ:

			if(s_Boton_LowFreq())
			{
				time=2;
				estado=LOW_FREQ;
			}
			break;

		case LOW_FREQ:
			if(s_Boton_HighFreq())
			{
				time=1;
				estado=HIGH_FREQ;
			}
			break;

		default:
			time=1;
			estado=HIGH_FREQ;
	}
}
