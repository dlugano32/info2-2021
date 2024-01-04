/*
 * Leds.h
 *
 *  Created on: 25 ago. 2021
 *      Author: marup
 */

#ifndef LEDS_H_
#define LEDS_H_

#include "LPC845.h"

#define AZUL	0
#define VERDE	1
#define ROJO	2

#define LED_AZUL   	1, 1
#define LED_VERDE	1, 0
#define LED_ROJO	1, 2


void prenderLed(uint8_t);
void apagarLed(uint8_t);

#endif /* LEDS_H_ */
