/*
 * DR_Tecla.h
 *
 *  Created on: 25 nov. 2021
 *      Author: d_lugano
 */

#ifndef DR_TECLA_H_
#define DR_TECLA_H_

typedef unsigned char uint8_t;

#define BOTONP04 4
#define NO_KEY 255
#define DEBOUNCE 50	 //50ms

void BarridoTecla(void);

extern uint8_t Tecla;

#endif
