/*
 * OperacionMde.c
 *
 *  Created on: 24 jul. 2021
 *      Author: d_lugano
 */


#include "OperacionMde.h"
#include "OperacionMde_func.h"
#include "ModoAutomatico.h"
//Faltaria agregar los includes de las otras MdE que no fueron pedidas en el ejercicio


static unsigned char flagAut=0;
static unsigned char flagIncendio=0;
static unsigned char flagAsc=0;

void OperacionMde(void)
{
	static unsigned char estado=AUTOMATICO;

	switch(estado)
	{
		case AUTOMATICO:
			if(s_LlaveIncendio() == 0 && s_LlaveModo() == 0)
			{
				flagAut=0;
				flagAsc=1;
				init_ModAscMde();
				estado=ASCENSORISTA;
			}

			if(s_LlaveIncendio() == 1)
			{
				flagAut=0;
				flagIncendio=1;
				init_ModIncendioMde();
				estado=INCENDIO;
			}

			if(flagAut==1)	//Esta va ultima para que si cambiaron los estados de las llaves, no entre a esta MdE
			{
				ModAutMde();
				estado=AUTOMATICO;
			}

			break;

		case INCENDIO:
			if(s_LlaveIncendio() == 0 && s_LlaveModo() == 1)
			{
				flagIncendio=0;
				flagAut=1;
				init_ModAutMde();
				estado=AUTOMATICO;
			}

			if(s_LlaveIncendio() == 0 && s_LlaveModo() == 0)
			{
				flagIncendio=0;
				flagAsc=1;
				init_ModAscMde();
				estado=ASCENSORISTA;
			}

			if(flagIncendio==1) //Esta va ultima para que si cambiaron los estados de las llaves, no entre a esta MdE
			{
				ModIncendioMde();
				estado=INCENDIO;
			}

			break;

		case ASCENSORISTA:
			if(s_LlaveIncendio()==1)
			{
				flagAsc=0;
				flagIncendio=1;
				init_ModIncendioMde();
				estado=INCENDIO;
			}

			if(s_LlaveIncendio()==0 && s_LlaveModo()==1)
			{
				flagAsc=0;
				flagAut=1;
				init_ModAutMde();
				estado=AUTOMATICO;
			}

			if(flagAsc==1) //Esta va ultima para que si cambiaron los estados de las llaves, no entre a esta MdE
			{
				ModAscMde();
				estado=ASCENSORISTA;
			}
			break;

		default:
			flagAut=1;
			flagIncendio=0;
			flagAsc=0;
			init_ModAutMde();
			estado=AUTOMATICO;
	}
}

void init_OperacionMde(void)
{
	flagAut=1;
	flagIncendio=0;
	flagAsc=0;
	init_ModAutMde();
}
