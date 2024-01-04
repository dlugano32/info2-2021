/*
 * Systick.c
 *
 *  Created on: 16 nov. 2021
 *      Author: d_lugano
 */
#include "Systick.h"

void InitSystick(void)
{
	SYSTICK->CSR=	(1<<0)	//Habilito el systick
				|	(1<<1)	//Interrupciones activadas
				|	(1<<2);	//Seteo el tick clock a la frecuencia del CPU (30MHz)

	SYSTICK->RVR=75000-1;	//Configuro el systick cada 2,5ms
	SYSTICK->CVR=SYSTICK->RVR;	//
}

void SysTick_Handler(void)
{
	uint32_t=SYSTICK->CSR;
	BarridoTeclado();
	BarridoDisplay();
}
