/*
 * Tecla.h
 *
 *  Created on: 26 ago. 2021
 *      Author: d_lugano
 */

#ifndef TECLA_H_
#define TECLA_H_

#include "../Drivers/LPC845.h"
#include "../Drivers/DR_teclado.h"

#define BOTON_STICK 0, 4

uint32_t getKey(void);

#endif /* TECLA_H_ */
