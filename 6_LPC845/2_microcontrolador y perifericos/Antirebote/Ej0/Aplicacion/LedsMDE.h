/*
 * LedsMDE.h
 *
 *  Created on: 9 sep. 2021
 *      Author: d_lugano
 */

#ifndef LEDSMDE_H_
#define LEDSMDE_H_

#define F0_25 	0
#define F0_5  	1
#define F1		2
#define F2		3
#define APAGADO 4

extern uint8_t colorLed;

void LedsMDE(void);
void InitLedsMDE(void);


#endif /* LEDSMDE_H_ */
