/*
 * CtrlAccesoMde.c
 *
 *  Created on: 22 jul. 2021
 *      Author: d_lugano
 */


#include "CtrlAccesoMde.h"
#include "CtrlAccesoMde_func.h"

//Variables extern
int verificacion=0;
int flagT0=0;

//Variable global a este archivo
static unsigned int id=0;

void CtrlAccesoMde(void)
{
	static unsigned char estado=WAIT_BEGIN;

	switch (estado)
	{
		case WAIT_BEGIN:
			if(dato=='$')
			{
				estado=WAIT_ID;
			}
			break;

		case WAIT_ID:
			if(dato=='#')
			{
				estado=WAIT_BEGIN;
			}

			if(dato!='$' && dato!='#')
			{
				id=dato;
			}
			break;

		case WAIT_END:
		{
			if(dato=='$')
			{
				id=0;
				estado=WAIT_ID;
			}

			if(dato=='#')
			{
				m_IniciarT0_10s();
				verificacion=verificar(id);
				estado=VERIFICANDO;
			}
		}
			break;

		case VERIFICANDO:

			if(verificacion==NOvERIFICADO || flagT0==1)
			{
				id=0;
				flagT0=0;
				estado=WAIT_BEGIN;
			}

			if(verificacion==VERIFICADO)
			{
				m_StopT0();
				id=0;
				estado=WAIT_BEGIN;
			}

			if(verificacion==VERIFICANDO)
			{
				verificacion=verificar(id);
				estado=VERIFICANDO;

			}

			break;

		default:
			verificacion=-1;
			flagT0=0;
			id=0;
			m_StopT0();
			estado=WAIT_BEGIN;
	}
}

void init_CtrlAccesoMde(void)
{
	verificacion=-1;
	flagT0=0;
	id=0;
	m_StopT0();
}
