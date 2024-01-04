/*
 * DR_USART.h
 *
 *  Created on: 25 nov. 2021
 *      Author: d_lugano
 */

#ifndef DR_USART_H_
#define DR_USART_H_

#define TAM 32

typedef unsigned int uint32_t;
typedef unsigned char uint8_t;
typedef short int int16_t;

int16_t PopTx(void);
void PushTx(uint8_t);

#endif /* DR_USART_H_ */
