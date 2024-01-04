/*
 * PR_7Seg.c
 *
 *  Created on: 27 sep. 2021
 *      Author: chor
 */

#include "PR_7Seg.h"

void Display ( uint8_t ndisplay , uint32_t numero )
{
	uint8_t i,i_final;

	if ( ndisplay == 0 )
		i = 3;
	else
		i = 6;

	i_final = i - 3;

	for ( ; i > i_final ; i-- )
	{
		display[i-1] = numero%10;
		numero /= 10;
	}
}
