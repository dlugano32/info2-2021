/*
 * PR_ESP82gg.c
 *
 *  Created on: 18 nov. 2021
 *      Author: d_lugano
 */

#include "PR_ESP8266.h"

/*
void EnviarDatos(uint8_t key, uint32_t timestap)
{
	uint8_t buffer[20], i=0;
	buffer[0]='#';
	buffer[1]=' ';

	for(i=2; timestap>=0; i++)	//Hasta que timestap sea cero
	{
		buffer[i]%=timestap+48;	//Lo paso a ascii
		timestap/=10;
	}

	buffer[++i]=' ';
	buffer[++i]=key+48;
	buffer[++i]=' ';
	buffer[++i]='#';
	buffer[++i]='\0';

	TxSerie1(buffer);
}
*/
