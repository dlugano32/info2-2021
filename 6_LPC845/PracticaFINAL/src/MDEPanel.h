/*
 * MDEPanel.h
 *
 *  Created on: 21 nov. 2021
 *      Author: d_lugano
 */

#ifndef MDEPANEL_H_
#define MDEPANEL_H_

#include "LPC845.h"

#define SEL_AMBIENTE 0
#define SEL_CONTROL 1
#define SEL_ACCION 2

extern uint8_t valTemp;

void MDEPanel(void);
void EnviarTrama( uint8_t hab, uint8_t control, uint8_t accion);

#endif /* MDEPANEL_H_ */
