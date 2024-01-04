/*
 * DR_Sensor.c
 *
 *  Created on: 25 nov. 2021
 *      Author: d_lugano
 */


#include "DR_Sensor.h"

uint32_t distancia=0;

void DR_SensorDistancia(uint32_t value)
{
	distancia=(value*5)/2;	//Para evitar que el micro haga una operacion con punto flotante, lo multiplico por 5 y lo divido por 2
}
