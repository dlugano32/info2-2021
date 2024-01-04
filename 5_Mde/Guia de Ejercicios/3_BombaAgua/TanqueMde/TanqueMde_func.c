/*
 * TanqueMde_func.c
 *
 *  Created on: 19 jul. 2021
 *      Author: d_lugano
 */


//Mde
void init_TanqueMde (void)
{
	m_BombaOff();
}

//Eventos
int s_LlaveON(void)
{
	return Entrada (0); 	//Se pone en uno cuando quiero prender el sistema
}

int s_LlaveOff(void)
{
	return Entrada (0);	//Se pone en uno cuando se quiere apagar el sistema
}

int s_Sensor_vacio(void)
{
	return Entrada (1);
}

int s_Sensor_lleno(void)
{
	return Entrada (2);
}

//Acciones
void m_BombaOff(void)
{
	Relays(0,0);
}

void m_BombaON(void )
{
	Relays(0,1);
}
