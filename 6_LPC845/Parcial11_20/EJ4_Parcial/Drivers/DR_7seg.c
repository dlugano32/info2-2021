/*
 * DR_7seg.c
 *
 *  Created on: 16 nov. 2021
 *      Author: d_lugano
 */

uint8_t DigitoDisplay[N_Digitos]={0,0,0,0};

void BarridoDisplay(void)
{
	const uint8_t TablaDigitosBCD[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
	static uint8_t indice=0;
	uint8_t aux;
	//Arranco con todos los displays apagados
	SetPIN(DIG0, 1);
	SetPIN(DIG1, 1);
	SetPIN(DIG2, 1);
	SetPIN(DIG3, 1);

	aux=TablaDigitosBCD[ DigitoDisplay[indice] ];

	SetPIN(segA,( (aux>>0) & (uint8_t)1 ) );
	SetPIN(segB,( (aux>>1) & (uint8_t)1 ) );
	SetPIN(segC,( (aux>>2) & (uint8_t)1 ) );
	SetPIN(segD,( (aux>>3) & (uint8_t)1 ) );
	SetPIN(segE,( (aux>>4) & (uint8_t)1 ) );
	SetPIN(segF,( (aux>>5) & (uint8_t)1 ) );
	SetPIN(segG,( (aux>>6) & (uint8_t)1 ) );

	switch(indice)
	{
		case 0:
			SetPIN(DIG0, 0);
			break;
		case 1:
			SetPIN(DIG1, 0);
			break;
		case 2:
			SetPIN(DIG2, 0);
			break;
		case 3:
			SetPIN(DIG3, 0);
			break;
	}
	indice++;
	indice%=N_DIGITOS;
}

void Display(uint8_t num_display, uint32_t datoT, uint32_t datoH)
{
	uint8_t i=0;

	if(datoT>99)
		datoT=99;

	if(datoH>99)
		datoH=99;

	if(num_display == 0)
	{
		for(i=4; i>2; i--)
		{
			DigitoDiplay[i-1]=datoT%10;
			valor/=10;
		}
	}
	else
	{
		for(i=2; i>0; i--)
		{
			DigitoDiplay[i-1]=datoH%10;
			valor/=10;
		}
	}
}
