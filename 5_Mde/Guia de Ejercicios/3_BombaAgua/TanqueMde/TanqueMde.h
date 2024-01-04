/*
 * TanqueMde.h
 *
 *  Created on: 19 jul. 2021
 *      Author: d_lugano
 */

#ifndef TANQUEMDE_H_
#define TANQUEMDE_H_

#define APAGADO 0
#define LLENO 1
#define LLENANDO 2

//Mde
void TanqueMde (void);
void init_TanqueMde (void);

//Eventos
int s_LlaveON(void);
int s_LlaveOff(void);
int s_Sensor_vacio(void);
int s_Sensor_lleno(void);

//Acciones
void m_BombaOff(void);
void m_BombaON(void );

#endif /* TANQUEMDE_H_ */
