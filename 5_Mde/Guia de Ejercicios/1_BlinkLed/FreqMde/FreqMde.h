/*
 * FreqMde.h
 *
 *  Created on: 19 jul. 2021
 *      Author: d_lugano
 */

#ifndef FREQMDE_H_
#define FREQMDE_H_

#define HIGH_FREQ 0
#define LOW_FREQ 1

extern int time;

//Mde
void FreqMde();
void init_FreqMde();

//Eventos

int s_Boton_LowFreq(void);
int s_Boton_HighFreq(void);

#endif
