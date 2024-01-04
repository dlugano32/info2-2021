/*
 * DR_ADC.c
 *
 *  Created on: 16 nov. 2021
 *      Author: d_lugano
 */

#include "DR_ADC.h"

uint32_t ValorTemp=0;
uint32_t ValorHum=0;

void InitADC(void)
{
	uint16_t DIV=0;

	SYSCON->PDRUNCFG|=(1<<4);	//PowerADC

	SYSCON->SYSAHBCLKCTRL0|=(1<<24);	//Habilito el CLK
	SYSCON->ADCCLKSEL=0;	//Selecciono el CLK del ADC a 30MHz
	SYSCON->ADCCLKDIV=0;	//Sin divisores

	SYSCON->SYSAHBCLKCTRL0|= (1<<7);	//Habilito la SWM
	PINENABLE0&= ~( ( 1<< 15) | (1<<19) );	//Habilito el canal 1 y 5

	//Calibracion del ADC
	ADC->CTRL=( 60 | (1<<30));		//Divido el CLK de 30MHz por 60 y me quedan 500KHz que es lo que necesito para calibrar

	while(ADC->CTRL & (1<<30));		//Espero a que termine la calibracion

	//Configuracion del ADC
	DIV=CLK/(25 * SAMPLE);	//El divisor para configurar el sample rate

	ADC->CTRL=	(DIV-1 )
			|	(0 << 8)
			|	(0 << 10)
			|	(0 << 30);

	//Configuro la secuencia A
	ADC->SEQA_CTRL=	(1<<1)
				|	(1<<5)
				|	(0<<12)
				|	(1<<27)
				|	(0<<30)
				|	(1<<31);

	ADC->SEQB_CTRL=0;
	ADC->TRM&= ~(1<<5);

	ADC->INTEN|= (1<<0);
	ISER0|= (1<<16);

}

void ADC_SEQA_IRQHandler(void)
{
	uint32_t accTemp=0, accHum=0;
	uint8_t contT=0, contH=0;

	if( ADC->DAT1 & (1<<31) )
	{
		accTemp+= ( (ADC->DAT1 >> 4) & 0xFFF);
		contT++;
	}

	if( ADC->DAT5 & (1<<31) )
	{
		accHum+= ( (ADC->DAT5 >> 4) & 0xFFF);
		contH++;
	}

	if(contT>=50)
	{
		ValorTemp=format(accTemp/contT);
		contT=0;
	}

	if(contH>=50)
	{
		ValorHum=format(accHum/contH);
		contH=0;
	}
}
