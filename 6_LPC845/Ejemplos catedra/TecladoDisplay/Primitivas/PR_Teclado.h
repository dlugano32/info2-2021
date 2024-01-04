/*
 * Tecla.h
 *
 *  Created on: 26 ago. 2021
 *      Author: d_lugano
 */

#ifndef PR_TECLADO_H_
#define PR_TECLADO_H_

#include "LPC845.h"
#include "DR_teclado.h"

#define BOTON_STICK 0, 4

uint32_t getKey(void);

#endif /* PR_TECLADO_H_ */
