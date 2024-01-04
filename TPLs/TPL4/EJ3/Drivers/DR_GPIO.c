#include "DR_GPIO.h"
#include "Tecla.h"

void InitGPIO(void)
{
	SYSCON->SYSAHBCLKCTRL0 |= (1 << SYSCON_SYSAHBCLKCTRL0_GPIO0_SHIFT);
	SYSCON->SYSAHBCLKCTRL0 |= (1 << SYSCON_SYSAHBCLKCTRL0_GPIO1_SHIFT);

	SetDIR(BOTON_STICK, ENTRADA);

	SetPINMODE_IN(IOCON_INDEX_PIO0_4, 0x2);
}

void SetDIR (uint32_t Puerto, uint32_t Pin, uint32_t Direccion)	//Setea los pines como Entradas o salidas 0=entrada - 1=salida
{
	if(Direccion == 1)
		GPIO->DIR[Puerto] |= (1<<Pin);
	else
		GPIO->DIR[Puerto] &= ~(1<<Pin);
}

void SetPIN (uint32_t Puerto, uint32_t Pin, uint32_t Estado)	//Setea el Estado (0 o 1) indicado en el pin especificado
{
	if(Estado == 1)
		GPIO->PIN[Puerto] |= (0x01<<Pin);	//Set
	else
		GPIO->PIN[Puerto] &= ~(0x01<<Pin);	//Clear
}

uint32_t GetPIN (uint32_t Puerto, uint32_t Pin) //Devuelve el valor del pin especificado
{
	uint32_t ret=0;

	if( ( GPIO->PIN[Puerto] & (0x01<<Pin) ) != 0)
		ret=1;

	return ret;
}


//0x0 Inactive (no pull-down/pull-up resistor enabled).
//0x1 Pull-down resistor enabled.
//0x2 Pull-up resistor enabled.
//0x3 Repeater mode.

void SetPINMODE_IN (uint32_t pin_index, uint32_t Modo)
{
	IOCON->PIO[pin_index]=  ( (IOCON->PIO[pin_index] & (~(IOCON_PIO_MODE_MASK))) | (Modo<< IOCON_PIO_MODE_SHIFT) );
}

//Open-drain mode.
//0 Disable.
//1 Open-drain mode enabled

void SetPINMODE_OUT (uint32_t pin_index, uint32_t Modo)	//Drain Mode
{
	if(Modo == 1)
		IOCON->PIO[pin_index] |= (1<<IOCON_PIO_OD_SHIFT);
	else
		IOCON->PIO[pin_index] &= ~(1<<IOCON_PIO_OD_SHIFT);
}
