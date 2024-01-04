#ifndef DR_INIT_H_
#define DR_INIT_H_

//Registros de control del FRO y del CLK

//Direccion de la funcion de ROM para setear la frecuencia del oscilador:
#define FRO_SET_FRECUENCY_FUNC ( 0x0F0026F5U)

#include "Systick.h"
#include <DR_GPIO.h>
#include <PR_Leds.h>
#include <PR_Timers.h>
#include "DR_teclado.h"

void InitHw(void);
void InitPLL(void);

#endif /* DR_INIT_H_ */
