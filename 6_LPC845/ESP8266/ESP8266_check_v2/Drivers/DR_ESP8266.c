/*
 * DR_ESP8266.c
 *
 *  Created on: 30 oct. 2021
 *      Author: d_lugano
 */


#include "DR_ESP8266.h"

//Datos a enviar para la configuracion del esp8266

/*
 sendData("AT+RST\r\n",2000);      // resetear módulo
 sendData("AT+CWMODE=1\r\n",1000); // configurar como cliente
 sendData("AT+CWJAP=\"SSID\",\"PASSWORD\"\r\n",8000); //SSID y contraseña para unirse a red
 sendData("AT+CIFSR\r\n",1000);    // obtener dirección IP
 sendData("AT+CIPMUX=1\r\n",1000); // configurar para multiples conexiones
 sendData("AT+CIPSERVER=1,80\r\n",1000);         // servidor en el puerto 80
*/

/*
void InitESP8266(void)
{
	TxSerie((uint8_t*)"AT+RST\r\n");				//Resetea el modulo
	TxSerie((uint8_t*)"AT+CWMODE=1\r\n");			//Configuramos al esp como cliente->solo se conecta a nuestra red
	TxSerie((uint8_t*)"AT+CWJAP=\"Fibertel WiFi982 2.4GHz\",\"0141832376\"\r\n");	//Nos conectamos al WiFi
	TxSerie((uint8_t*)"AT+CIPMUX\r\n");			//Modo multiconexion
	TxSerie((uint8_t*)"AT+CIPSERVER=1,80\r\n");	//Servidor en el puerto 80
	TxSerie((uint8_t*)"AT+CIFSR\r\n");			//Obtengo la direccion IP del ESP8266 en LAN
}

*/
