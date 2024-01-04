/*
 * App.c
 *
 *  Created on: 12 nov. 2021
 *      Author: d_lugano
 */

#include "App.h"

void SerieMde(void)
{
	static uint8_t estado=ENVIAR;
	static uint8_t aux=0;
	int8_t dato=0;

	switch(estado)
	{
		case ENVIAR:
			if( getKey() == PUSH)
			{
				aux++;
				if(aux ==4)
					aux=1;

				Tx1Byte('#');
				Tx1Byte(aux);
				Tx1Byte('$');

				estado=RECIBIR;
			}
			break;

		case RECIBIR:

				dato = LecturaSerie();

				if ( dato != -1 )
				{
					switch(dato)
					{
						case 1:
							LED_ON(ROJO);
							LED_OFF(AZUL);
							LED_OFF(VERDE);
							break;
						case 2:
							LED_OFF(ROJO);
							LED_OFF(AZUL);
							LED_ON(VERDE);
							break;
						case 3:
							LED_OFF(ROJO);
							LED_ON(AZUL);
							LED_OFF(VERDE);
							break;
					}
					estado=ENVIAR;
				}
				else
					estado=RECIBIR;
				break;
	}
}
