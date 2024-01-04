/*
 * MDE_funciones.c
 *
 *  Created on: 11 oct. 2021
 *      Author: d_lugano
 */

#include "MDE_funciones.h"

int32_t points=0;
uint8_t errores=0;

uint8_t Puntaje(uint32_t counter, uint32_t timestap , uint32_t dificultad )
{
	//Legend 	500 	counter=timestap
	//Perfect  	100 	+-0.4*dificultad
	//Good   	50		+-0.8*dificultad
	//Regular 	10 		+-dificultad
	//Bad		-20

	if(timestap==counter)
	{
		points+=500;
		return 0;
	}
	else if ( ( (timestap-dificultad*0.4) < counter ) && ( (timestap + dificultad*0.4) > counter) )
	{
		points+=100;
		return 0;
	}
	else if( ( (timestap-dificultad*0.8) < counter ) && ( (timestap + dificultad*0.8) > counter) )
	{
		points+=50;
		return 0;
	}
	else if( ( (timestap-dificultad) < counter ) && ( (timestap + dificultad) > counter) )
	{
		points+=10;
		return 0;
	}

	return 0;
}

void Puntaje_restar(void)
{
	points-=20;
	errores++;
}

void InitArchivoMusica( Paso* steps)
{
	steps[0].timestap=1000;
	steps[0].tecla=UP_ARROW;

	steps[1].timestap=2000;
	steps[1].tecla=RIGHT_ARROW;

	steps[2].timestap=3000;
	steps[2].tecla=DOWN_ARROW;

	steps[3].timestap=4000;
	steps[3].tecla=LEFT_ARROW;

	steps[4].timestap=5000;
	steps[4].tecla=CROSS;

	steps[5].timestap=6000;
	steps[5].tecla=CIRCLE;

	steps[6].timestap=7000;
	steps[6].tecla=SQUARE;

	steps[7].timestap=8000;
	steps[7].tecla=TRIANGLE;
}
