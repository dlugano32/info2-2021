/*
 * App.h
 *
 *  Created on: 12 nov. 2021
 *      Author: d_lugano
 */

#ifndef APP_H_
#define APP_H_

#include "../Drivers/DR_Init.h"
#include "../Drivers/DR_UART.h"
#include "../Primitivas/PR_Uart.h"
#include "../Drivers/LPC845.h"
#include "../Primitivas/Tecla.h"
#include "../Primitivas/Leds.h"

#define ENVIAR 0
#define RECIBIR 1


void SerieMde(void);

#endif /* APP_H_ */
