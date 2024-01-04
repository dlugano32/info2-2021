#include "LPC845.h"
#include "App.h"

void SysTick_Handler(void)
{
	//Leo el registro de estado para limpiar el flag de interrupciones
	unsigned int aux = SYSTICK->CSR;

	static unsigned int contador=0;

	contador++;

	if(contador==1000)
	{
		flag_systick=1;
		contador=0;
	}
}
