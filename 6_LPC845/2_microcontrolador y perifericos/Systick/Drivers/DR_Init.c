#include "DR_Init.h"
#include "LPC845.h"
#include "gpio.h"
#include "Leds.h"

//Genero una funcion a partir de un puntero a función que llame a esa posición de memoria:
void (*fro_set_frec) (int ) = FRO_SET_FRECUENCY_FUNC;


void InitHw(void)
{
	InitPLL();
	InitGPIO();
	InitSystick();
}

void InitGPIO(void)
{
	//1-Habilito el clock para GPIO
	SYSCON->SYSAHBCLKCTRL0 |= (1 << SYSCON_SYSAHBCLKCTRL0_GPIO1_SHIFT);

	//2-Habilito los pines del puerto 1 de los leds como salidas
	SetDIR(PIN_LEDR, SALIDA);
	SetDIR(PIN_LEDG, SALIDA);
	SetDIR(PIN_LEDB, SALIDA);

	//4-Configuro todos los leds que estan como salidas con el open drain OFF
	SetPINMODE_OUT(IOCON_INDEX_PIO1_0, 0);
	SetPINMODE_OUT(IOCON_INDEX_PIO1_1, 0);
	SetPINMODE_OUT(IOCON_INDEX_PIO1_2, 0);
}

void InitPLL(void)
{
	//Seteo la frecuencia del fro a 30MHz, llamando a la funcion de ROM:
	fro_set_frec(30000);

	//Selecciono la salida del FRO como el clk principal del sistema:

	SYSCON->FROOSCCTRL |= 1<<17;

	//Refresco el registro para habilitar el clk de 30MHz:
	SYSCON->FRODIRECTCLKUEN &= ~1;
	SYSCON->FRODIRECTCLKUEN |= 1;

	//Seteo FRO como el clkSrc del PLL:
	SYSCON->MAINCLKPLLSEL = 0;

	SYSCON->MAINCLKPLLUEN &= ~1;
	SYSCON->MAINCLKPLLUEN |= 1;

	//Seteo FRO como el clkSrc del PLL:
	SYSCON->SYSPLLCLKSEL = 0;

	SYSCON->SYSPLLCLKUEN &= ~1;
	SYSCON->SYSPLLCLKUEN |= 1;

	SYSCON->SYSAHBCLKDIV = 1;
}

void InitSystick(void)
{
	SYSTICK->CSR=7;			//Pongo en 1 los ultimos 3 bits del registro
	SYSTICK->RVR=30000-1;	//Configuro el systick cada 1ms, le pongo -1 porque el micro tarda un tick mas en hacer el reload
	SYSTICK->CVR=SYSTICK->RVR;	//La primer recarga la tiene que hacer el usuario
}
