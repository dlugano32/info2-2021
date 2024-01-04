/*
 * DR_teclado.h
 *
 *  Created on: 16 sep. 2021
 *      Author: d_lugano
 */

#ifndef DR_TECLADO_H_
#define DR_TECLADO_H_

#include <DR_GPIO.h>
#include "LPC845.h"

extern uint8_t Tecla;

#define DEBOUNCE_COUNT 5

#define PUSH 0
#define NOT_PUSH 1

//Teclas teclado matricial:
//FILAS (ENTRADAS): P0.8, P0.30 y P0.31
#define	FILA0	0,8
//#define	FILA1	0,30
#define	FILA1	1,9	//En mi placa solde el 1,9
#define	FILA2	0,31

//COLUMNAS (SALIDAS): P0.27 y P0.28
#define	COL0	0,27
#define	COL1	0,28

#define IOCON_INDEX_FILA0	IOCON_INDEX_PIO0_8
//#define IOCON_INDEX_FILA1	IOCON_INDEX_PIO0_30
#define IOCON_INDEX_FILA1	IOCON_INDEX_PIO1_9 //En mi placa solde el 1,9
#define IOCON_INDEX_FILA2	IOCON_INDEX_PIO0_31


#define SW0 0
#define SW1 1
#define SW2 2
#define SW3 3
#define SW4 4
#define SW5 5
#define SW6 6

#define NO_KEY 255

void DriverTecladoSW(void);
uint8_t DriverTecladoHW(void);
uint8_t DriverTecladoMatricialHW(void);
void InitTecladoMatricial (void);
void InitGPIO(void);


#endif /* DR_TECLADO_H_ */
