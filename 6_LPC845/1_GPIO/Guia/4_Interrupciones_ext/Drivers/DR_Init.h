#ifndef DR_INIT_H_
#define DR_INIT_H_

#include "LPC845.h"
#include "Systick.h"
#include "IntExt.h"
#include "gpio.h"
#include "Leds.h"
#include "Tecla.h"
#include "Timer.h"

//Registros de control del FRO y del CLK

//Direccion de la funcion de ROM para setear la frecuencia del oscilador:
#define FRO_SET_FRECUENCY_FUNC ( 0x0F0026F5U)

void InitHw(void);
void InitGPIO(void);
void InitPLL(void);

#endif /* DR_INIT_H_ */
