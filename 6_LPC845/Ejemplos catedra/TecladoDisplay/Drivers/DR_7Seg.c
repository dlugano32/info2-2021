/*
 * DR_7Seg.c
 *
 *  Created on: 27 sep. 2021
 *      Author: chor
 */


#include "DR_7Seg.h"

uint8_t display[CANT_DIGITOS];

void Init7Segs ( void )
{
	uint8_t i;

	SetDIR( _7SEG_RST , SALIDA );
	SetDIR( _7SEG_CLK , SALIDA);
	SetDIR( _7SEG_BCDA , SALIDA);
	SetDIR( _7SEG_BCDB , SALIDA);
	SetDIR( _7SEG_BCDC , SALIDA);
	SetDIR( _7SEG_BCDD , SALIDA);

	SetPINMODE_IN(IOCON_INDEX_7SEG_RST, 3 );
	SetPINMODE_IN(IOCON_INDEX_7SEG_CLK, 3 );
	SetPINMODE_IN(IOCON_INDEX_7SEG_BCDA, 3 );
	SetPINMODE_IN(IOCON_INDEX_7SEG_BCDB, 3 );
	SetPINMODE_IN(IOCON_INDEX_7SEG_BCDC, 3 );
	SetPINMODE_IN(IOCON_INDEX_7SEG_BCDD, 3 );

	for ( i=0 ; i < CANT_DIGITOS ; i++)
		display[i] = 0;

}

void BarridoDisplay ( void )
{
	static uint8_t digito = 0;

	//Pongo el digito en el buffer:
	SetPIN(_7SEG_BCDA , display[digito] & 0x01 );
	SetPIN(_7SEG_BCDB , (display[digito]>>1) & 0x01 );
	SetPIN(_7SEG_BCDC , (display[digito]>>2) & 0x01 );
	SetPIN(_7SEG_BCDD , (display[digito]>>3) & 0x01 );

	//Muevo la señal de clk:
	if ( digito != 0 )
	{
		SetPIN(_7SEG_CLK,1);
		SetPIN(_7SEG_CLK,0);
	}
	else
	{
		SetPIN( _7SEG_RST , 1 );
		SetPIN( _7SEG_RST , 0 );
	}

	digito++;
	digito%=CANT_DIGITOS;

}
