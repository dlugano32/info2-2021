#include <netdb.h>//librerias a utilizar
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(int ac, char *av[])
{
    int res,i;				// resultado de algunas funciones
    int ssock;             		// descriptor del socket del servidor
    int csock;             		// descriptor del socket de la coneccion
    struct sockaddr_in my_addr;	        // mi direccion
    struct sockaddr_in cl_addr;	        // direccion del cliente
    unsigned int len;			// tamanio de la direccion
    char buf[1024];			// buffer de recepcion

    if(ac !=2)
    {
        printf("invocar %s <port_donde_servir>\n", av[0]);//msj de error que dice que argumentos hay que pasarle al programa
        return -1;
    }

    ssock = socket(AF_INET, SOCK_STREAM, 0); // crea un socket del tipo stream (TCP) en el dominio INET (internet)

    if(ssock < 0)
    {
        perror(strerror(errno));
        return -1;
    }
    my_addr.sin_family = AF_INET;   //familia del protocolo -> IPV4
    my_addr.sin_port = htons(atoi(av[1]));  //puerto que elijo para el server
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);    // es la direccion ip 0.0.0.0, permite que cualquier direccion ip se conecte al servidor
    //my_addr.sin_addr.s_addr = inet_addr("192.168.0.14");//si conozco la ip privada de la maquina en donde estoy sirviendo (ejecutando el programa server, puedo pasarle la direccion de esta manera)
    //cargo la direccion ip en el campo que corresponde de la estructura
    memset((void *) &(my_addr.sin_zero), '\0', 8);  //memset me carga o me llena una estructura o una parte de memoria con lo que yo le pida. acá lleno de ceros o de nulls un campo de la estructura del server, longitud del campo = 8



    res = bind(ssock, (struct sockaddr *)&my_addr, sizeof(my_addr));    // asigna la direcion al socket

    if(res < 0)
    {
        perror(strerror(errno));
        return -1;
    }

    printf(" sirviendo en %s:%d ...\n", inet_ntoa(my_addr.sin_addr), ntohs(my_addr.sin_port));

    listen(ssock, 5);   // espera conexiones entrantes

    len = sizeof(cl_addr);
    csock = accept(ssock, (struct sockaddr *)&cl_addr, &len);

    if(csock < 0)
    {
        perror(strerror(errno));
        return -1;

    }
    printf(" conectado desde %s:%d ...\n", inet_ntoa(cl_addr.sin_addr), ntohs(cl_addr.sin_port));//imprimo desde donde se conectan

    while(1)
    {
        memset(buf, 0, sizeof(buf));	// limpia el buffer de recepcion (lo llena con ceros)

        read(csock, buf, sizeof(buf));  	// lee el mensaje y lo almacena en buf

        printf("--- %s\n", buf); //imprimo buf, lo recibido

        printf(">>> ");
        fgets(buf,sizeof(buf),stdin);       // lee respuesta del teclado
        for (i=0;buf[i]!='\0';i++){         // lo uso para buscar el valor de i donde está el null
        }
        buf[i-1]='\0';      // elimino el salto de linea que escribió en nombre corriendo el null
        write(csock, buf, strlen(buf)+1);   // envia respuesta
    }

    close(ssock);
    return 0;
}
