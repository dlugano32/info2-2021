/*
 * App.h
 *
 *  Created on: 19 nov. 2021
 *      Author: d_lugano
 */

#ifndef APP_H_
#define APP_H_

#define DATE (* ((uint32_t *)0x40024038u) )

#define ESPERANDO_TRAMA 0
#define ESPERANDO_ID 1
#define ESPERANDO_CREDITO 2
#define BOTONERA 3
#define ESPERANDO_EXP 4
#define ERROR 5

void MDERecepcion(void);
uint8_t checkRecarga(uint8_t ID,uint8_t credito);
void Recarga(uint8_t ID, uint8_t credito);


#endif /* APP_H_ */
