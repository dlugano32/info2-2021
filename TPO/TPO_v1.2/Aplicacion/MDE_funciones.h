/*
 * MDE_funciones.h
 *
 *  Created on: 11 oct. 2021
 *      Author: d_lugano
 */

#ifndef MDE_FUNCIONES_H_
#define MDE_FUNCIONES_H_

#include "../Aplicacion/MDE_funciones.h"

#include "../Drivers/LPC845.h"

#include "../Aplicacion/JustDanceMDE.h"

uint8_t Puntaje(uint32_t counter, uint32_t timestap , uint32_t dificultad );
void Puntaje_restar();
void InitArchivoMusica( Paso*);

#endif /* MDE_FUNCIONES_H_ */
