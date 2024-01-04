/*
 * EntradasSalidas.c
 *
 *  Created on: 21 jul. 2021
 *      Author: d_lugano
 */

//Eventos
int OnOff(void)
{
	return Entrada(0);
}

int Parada(void)
{
	return Entrada(1);
}

int TempOK(void)
{
	int ret=0;

	//Algun procesamiento del dato

	return ret;
}

//Salidas
void Motor (int estado)
{
	Relays(0,estado);
}

void Pistolas (int estado)
{
	Relays(1,estado);
}

void Calefaccion (int estado)
{
	Relays(2,estado);
}
