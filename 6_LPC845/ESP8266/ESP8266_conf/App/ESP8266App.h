/*
 * ESP8266App.h
 *
 *  Created on: 1 nov. 2021
 *      Author: d_lugano
 */

#ifndef ESP8266APP_H_
#define ESP8266APP_H_

#include "LPC845.h"
#include "Tecla.h"
#include "PR_UART.h"
#include "Leds.h"

void ESP8266_check(void);

#define ESPERANDO_TX 0
#define ESPERANDO_O 1
#define ESPERANDO_K 2
#define ESPERANDO_R 3
#define ESPERANDO_N 4

#endif /* ESP8266APP_H_ */
