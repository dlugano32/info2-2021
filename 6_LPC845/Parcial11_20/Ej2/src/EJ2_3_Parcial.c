#include "LPC845.h"

typedef struct
{
	uint32_t IR;	//Offset 0x0000
	uint32_t TCR;	//Offset 0x0004
	uint32_t TC;	//Offset 0x0008
	uint32_t PR;	//Offset 0x000C
	uint32_t PC;	//Offset 0x0010

}PWMs;

#define PWM_BASE (0x40018000u)
#define PWM	((PWMs *) PWM_BASE)


int main(void)
{

	SYSCON->SYSAHBCLKCTRL0|= (1<<6);	// Habilito el clk del puerto 0
	SYSCON->SYSAHBCLKCTRL0|= (1<<20);	// Habilito el clk del puerto 1

	GPIO->DIR[0]|= ( (1<<22) | (1<<24));	//Configuro como salidas a P0.22 P0.24
	GPIO->PIN[0]|= ( (1<<22) | (1<<24));	//Escribo un uno a las salidas P0.22 P0.24

	GPIO->DIR[1]&= ~(1<<3);		//Configuro como entrada a P1.3

	return 0;
}

