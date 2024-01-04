#ifndef DR_INIT_H_
#define DR_INIT_H_

//Registros de control del FRO y del CLK

//Direccion de la funcion de ROM para setear la frecuencia del oscilador:
#define FRO_SET_FRECUENCY_FUNC ( 0x0F0026F5U)

#include "../Drivers/Systick.h"
#include "../Drivers/DR_GPIO.h"
#include "Leds.h"
#include "Tecla.h"
#include "Timer.h"
#include "../Drivers/DR_teclado.h"

void InitHw(void);
void InitPLL(void);

#endif /* DR_INIT_H_ */
