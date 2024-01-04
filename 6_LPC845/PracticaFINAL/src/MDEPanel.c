/*
 * MDEPanel.c
 *
 *  Created on: 21 nov. 2021
 *      Author: d_lugano
 */
#include "MDEPanel.h"

uint8_t valTemp=20;	//Valor de reset en 20

void MDEPanel(void)
{
	static uint8_t estado=SEL_AMBIENTE;
	static uint8_t habitacion, control, accion, op_exitosa=0;
	static uint8_t valLuz=4;	//Seteo el valor de reset en 4 (MAX)
	uint8_t key=0;

	switch(estado)
	{
		case SEL_AMBIENTE:
			key=getKey();

			if(key!=NO_KEY)
			{
				if(key==T_COM)
				{
					habitacion=COM;
					estado=SEL_CONTROL;
				}
				else if(key=T_DOM1)
				{
					habitacion=DOM1;
					estado=SEL_CONTROL;
				}
				else if(key==T_DOM2)
				{
					habitacion=DOM2;
					estado=SEL_CONTROL;
				}
			}
			break;

		case SEL_CONTROL:
			key=getKey();

			if(key!=NO_KEY)
			{
				if(key==T_LUZ)
				{
					Display(valLuz);
					control=LUZ;
					estado=SEL_ACCION;
				}
				else if(key==T_CLIMA)
				{
					Display(valTemp);
					control=CLIMA;
					estado=SEL_ACCION;
				}
			}

			break;

		case SEL_ACCION:
			key=getKey();

			if(key!=NO_KEY)
			{
				if(key==T_MAS)
				{
					if(control==LUZ)
					{
						if(valLuz<4)
						{
							valLuz++;
							op_exitosa=1;
						}
					}
					else if(control==CLIMA)
					{
						if(valTemp<30)
						{
							valTemp++;
							op_exitosa=1;
						}
					}
				}
				else if(key==T_MENOS)
				{
					if(control==LUZ)
					{
						if(valLuz>1)
						{
							valLuz--;
							op_exitosa=1;
						}
					}
					else if (control==CLIMA)
					{
						if(valTemp>16)
						{
							valTemp--;
							op_exitosa=1;
						}
					}
				}
			}

			if(op_exitosa)	//Para que todas estas instrucciones se ejecuten solo una vez
			{
				op_exitosa=0;

				if(control==LUZ)
				{
					ModificarLuz(habitacion, valLuz);
				}
				else if(control==CLIMA)
				{
					ModificarTemperatura(habitacion, valTemp);
				}

				EnviarTrama(habitacion, control, accion);
				estado=SEL_AMBIENTE;
			}

			break;

		default:
			estado=SEL_AMBIENTE;
	}
}

void EnviarTrama( uint8_t hab, uint8_t control, uint8_t accion)
{
	uint8_t buffer[5];

	buffer[0]='$';
	buffer[1]=hab;
	buffer[2]=control;
	buffer[3]=accion;
	buffer[4]='#';

	TxSerie(buffer);
}
