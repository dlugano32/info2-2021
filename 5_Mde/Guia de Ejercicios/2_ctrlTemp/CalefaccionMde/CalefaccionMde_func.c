/*
 * CalefaccionMde_func.c
 *
 *  Created on: 19 jul. 2021
 *      Author: d_lugano
 */

#include "CalefaccionMde.h"

//Mde
void init_calefaccionMde(void)
{
	m_calentadorOff();
}

//Eventos
int s_Boton(void)
{
	return Entradas(0);
}

int getTemperatura(void)
{
	int Temp;

	Temp = -50+ 40*(cuentas*3.3)/4096;

	return Temp;
}

//Acciones
void m_calentadorOff(void)
{
	Relays(0, 0);	//Uso un Relay para desactivar el calentador
}

void m_calentadorON(void)
{
	Relays(0,1);	//Uso un Relay para activar el calentador
}
