/*
 * JustDanceMDE.h
 *
 *  Created on: 7 oct. 2021
 *      Author: d_lugano
 */

#ifndef JUSTDANCEMDE_H_
#define JUSTDANCEMDE_H_

#include "../Drivers/LPC845.h"
#include "../Primitivas/Leds.h"
#include "../Primitivas/Timer.h"
#include "../Primitivas/Tecla.h"

#include "../Primitivas/PR_Matriz.h"

#define MENU_PRINCIPAL 0
#define	CUENTA_ATRAS 1
#define ESPERANDO_TECLA 2
#define GAME_OVER 3

#define LARGO_CANCION 10000
#define CANT_PASOS 8

#define FACIL 500
#define DIFICIL 400

typedef struct
{
	uint32_t timestap;
	uint32_t tecla;
}Paso;

extern Paso cancion[CANT_PASOS];
extern int32_t points;
extern uint8_t errores;

void JustDanceMDE(void);
void clearMDE(void);
void InitJustDanceMDE(void);

#endif /* JUSTDANCEMDE_H_ */
