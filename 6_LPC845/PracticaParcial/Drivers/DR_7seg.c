/*
 * DR_7seg.c
 *
 *  Created on: 17 nov. 2021
 *      Author: d_lugano
 */

#include "DR_7seg.h"

uint8_t DigitoDisplay[N_Digitos];	//Variable global

void BarridoDisplays(void)
{
	const uint8_t TablaConversion_DecimalBCD[10]={0x60,0xF9,0xA4};	//Esta tabla esta hecha para anodo comun
	const uint8_t LetraE=0x79;
	uint8_t aux=0;
	static uint8_t Indice=0;

	if(DigitoDisplay[Indice]=='E')	//El ascii es 69
		aux=LetraE;
	else
		aux=TablaConversion_DecimalBCD[ DigitoDisplay[Indice] ];

	//Todos los digitos estan apagados

	//Escribo en el display
	SetPIN(segA,((aux>>0) & (uint8_t)1) );
	SetPIN(segB,((aux>>1) & (uint8_t)1) );
	SetPIN(segC,((aux>>2) & (uint8_t)1) );
	SetPIN(segD,((aux>>3) & (uint8_t)1) );
	SetPIN(segE,((aux>>4) & (uint8_t)1) );
	SetPIN(segF,((aux>>5) & (uint8_t)1) );
	SetPIN(segG,((aux>>6) & (uint8_t)1) );

	if(Indice==3)
		SetPIN(SegDP,0);	//ON
	else
		SetPIN(SegDP,1);	//OFF

	Indice++;
	Indice%=N_DIGITOS;

}
