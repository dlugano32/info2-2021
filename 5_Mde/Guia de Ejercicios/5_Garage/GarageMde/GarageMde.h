/*
 * GarageMde.h
 *
 *  Created on: 20 jul. 2021
 *      Author: d_lugano
 */

#ifndef GARAGEMDE_H_
#define GARAGEMDE_H_

#define STANDBY 0
#define OBST_ENTRADA 1
#define OBSTRUCCION 2
#define OBST_SALIDA 3

void GarageMde(void);
void init_GarageMde(void);
int HayObstruccion(void);
int Libre(void);

#endif /* GARAGEMDE_H_ */
