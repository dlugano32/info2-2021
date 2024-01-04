/*
 * LedMde_funciones.c
 *
 *  Created on: 19 jul. 2021
 *      Author: d_lugano
 */


//Mde
void init_LedMde(void)
{
	m_LedOff();
	flag_Led=1;
	flagT0=0;
	m_stopT0;
}

//Eventos
int s_Boton(void)
{
	return Entrada(0); //La entrada digital simula el boton
}

//Acciones
void m_LedON (void)
{
	LedsRGB(1, 1);	//Prendo el led rojo
}

void m_LedOff(void)
{
	LedsRGB(1, 0);	//Apago el led rojo
}

void m_iniciarT0 (void)
{
	TimerStart(0, time, handler0(), SEG);	//time es una variable externa de FreqMde
}

void m_StopT0(void)
{
	TimerStop(0);
}

void handler0(void)
{
	flagT0=1;
}
