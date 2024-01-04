/*
 * PR_USART.h
 *
 *  Created on: 25 nov. 2021
 *      Author: d_lugano
 */

#ifndef PR_USART_H_
#define PR_USART_H_

#include "DR_USART.h"

void TxSerie(uint8_t * buffer);
void EnviarTrama(uint32_t dato);


#endif /* PR_USART_H_ */
