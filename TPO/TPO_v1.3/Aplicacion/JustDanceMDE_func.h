/*
 * MDE_funciones.h
 *
 *  Created on: 11 oct. 2021
 *      Author: d_lugano
 */

#ifndef JUSTDANCEMDE_FUNC_H_
#define JUSTDANCEMDE_FUNC_H_

#include "../Aplicacion/JustDanceMDE_func.h"

#include "../Drivers/LPC845.h"

#include "../Aplicacion/JustDanceMDE.h"

uint8_t Puntaje(uint32_t counter, uint32_t timestap , uint32_t dificultad );
void Puntaje_restar();
void InitArchivoMusica( Paso*);
void EnviarStart(void);
void EnviarDatos(uint8_t key, uint32_t timestap);

void my_revstr (uint8_t *str, uint8_t *str_r);
void my_strcat (uint8_t *destino, uint8_t *origen);
uint8_t my_strlen(uint8_t* str1);


#endif /* JUSTDANCEMDE_FUNC_H_ */
