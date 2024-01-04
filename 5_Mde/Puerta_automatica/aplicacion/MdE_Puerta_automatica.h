/*
 * MdE_Puerta_automatica.h
 *
 *  Created on: 4 jul. 2021
 *      Author: d_lugano
 */

#ifndef MDE_PUERTA_AUTOMATICA_H_
#define MDE_PUERTA_AUTOMATICA_H_


#define CERRADO 0
#define ABIERTO 1
#define CERRANDO 2
#define ABRIENDO 3
#define EMERGENCIA 4

void Mde_init(void);
void MdE_Puerta_automatica(void);

#endif /* MDE_PUERTA_AUTOMATICA_H_ */
