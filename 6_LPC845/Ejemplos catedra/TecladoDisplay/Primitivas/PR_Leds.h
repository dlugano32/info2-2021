/*
 * Leds.h
 *
 *  Created on: 26 ago. 2021
 *      Author: d_lugano
 */

#ifndef PR_LEDS_H_
#define PR_LEDS_H_

#include "LPC845.h"

#define ROJO 2
#define VERDE 0
#define AZUL 1

#define L_ON 0
#define L_OFF 1

void LED_OFF( uint32_t Color);
void LED_ON( uint32_t Color);
void SwapEstadoLed(uint32_t Color);
void Leds ( uint8_t , uint8_t );


#endif /* PR_LEDS_H_ */

