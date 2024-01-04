#include "Systick.h"
#include "DR_7seg.h"

uint8_t flagsT[CANT_TIMERS];
uint32_t timers[CANT_TIMERS];

void SysTick_Handler(void)
{
	static uint8_t counter=0;

	AnalizarTimers();
	DriverTecladoSW();

	if(++counter == (uint8_t)30/N_DIGITOS)
	{
		counter=0;
		BarridoDisplay();
	}
}

void AnalizarTimers(void)
{
	//Leo el registro de estado para limpiar el flag de interrupciones
	uint8_t aux = SYSTICK->CSR;

	uint8_t i=0;

	for(i=0; i < CANT_TIMERS; i++)
	{
		if(timers[i]!=0)
		{
			timers[i]--;

			if(timers[i]==0)
			{
				flagsT[i]=1;
			}
		}
	}
}

void InitSystick(void)
{
	SYSTICK->CSR=7;			//Pongo en 1 los ultimos 3 bits del registro
	SYSTICK->RVR=30000-1;	//Configuro el systick cada 1ms, le pongo -1 porque el micro tarda un tick mas en hacer el reload
	SYSTICK->CVR=SYSTICK->RVR;	//La primer recarga la tiene que hacer el usuario
}
