/*
 * PR_ESP8266.H
 *
 *  Created on: 18 nov. 2021
 *      Author: d_lugano
 */

#ifndef PR_ESP8266_H_
#define PR_ESP8266_H_

#include "LPC845.h"
#include "PR_UART.h"

void EnviarDatos(uint8_t key, uint32_t counter);

#endif /* PR_ESP8266_H_ */
