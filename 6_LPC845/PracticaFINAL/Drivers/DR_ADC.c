/*
 * DR_ADC.c
 *
 *  Created on: 21 nov. 2021
 *      Author: d_lugano
 */
#include "DR_ADC.h"
#include "PR_SensorTemp.h"

void InitADC(void)
{
	uint8_t DIV;

	SYSCON->PDRUNCFG&= ~(1<<4);		//Energizo el periferico

	SYSCON->SYSAHBCLKCTRL0|=(1<<24);	//Habilito el CLK del ADC
	ADC->ADCCLKSEL&= ~(0x3);	//Pongo en 0 los ultimos dos bits para
	ADC->ADCCLKDIV|=1;		//Sin divisiones

	SYSCON->SYSAHBCLKCTRL0|=(1<<7);		//Habilito la SWM
	PINENABLE0&= ~(1<<19);	//Habilito el canal 5 del ADC


	//Calibracion
	ADC->CFG= ( 60 | (1<<30) );		//Pongo el ADC CLK a 500KHz y lo calibro
	while(ADC->CFG & (1<<30));

	//Configuracion
	DIV=CLK_ADC/(25*1000);

	ADC->CTRL=	(DIV-1)
			|	(0<<8)
			|	(0<<10)
			|	(0<<30);

	ADC->SEQA_CTRL=	(1<<5)
				|	(0<<12)
				|	(1<<27)	//Modo burst
				|	(1<<30)
				|	(0<<31);

	ADC->SEQB_CTRL=0;

	ADC->INTEN|=(1<<0);
	ISER0|=(1<<16);

	ADC->SEQA_CTRL|=(1<<31);	//Habilito la SEQA
}

void ADC_SEQA_IRQHandler(void)
{
	static uint32_t cont=0, aux=0;
	uint32_t conversion= (ADC->SEQA_GDAT>>4) & 0xFFF;

	cont++;
	aux+=conversion;

	if(cont>=50)
	{
		valADC=aux/50;
		aux=0;
		cont=0;
	}

}

