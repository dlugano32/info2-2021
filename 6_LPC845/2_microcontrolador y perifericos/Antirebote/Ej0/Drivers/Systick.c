#include "Systick.h"

uint8_t flagsT[CANT_TIMERS];
uint32_t timers[CANT_TIMERS];

void SysTick_Handler(void)
{
	AnalizarTimers();
	DriverTecladoSW();
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

void DriverTecladoSW(void)
{
	uint8_t key=NOT_PUSH;	//Tecla no presionada
	static uint8_t cont=0;

	key=GetPIN(BOTON_STICK);	//Me fijo el estado de la tecla

	if( key == PUSH && cont < DEBOUNCE_COUNT)
	{
		cont++;	//Cuenta cuantos milisegundos esta presionada la tecla
		if(cont == DEBOUNCE_COUNT)
		{
			Tecla=PUSH;	//Es decir, se esta presionando el boton. La variable Tecla es global y es la que va a estar devolviendo mi primitiva
		}
	}
	else if(key== NOT_PUSH)
	{
		cont=0;
	}
}

void InitSystick(void)
{
	SYSTICK->CSR=7;			//Pongo en 1 los ultimos 3 bits del registro
	SYSTICK->RVR=30000-1;	//Configuro el systick cada 1ms, le pongo -1 porque el micro tarda un tick mas en hacer el reload
	SYSTICK->CVR=SYSTICK->RVR;	//La primer recarga la tiene que hacer el usuario
}
