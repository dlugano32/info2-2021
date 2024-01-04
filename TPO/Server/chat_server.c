#include <netdb.h>//librerias a utilizar
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>


// mi IP publica es ("181.230.115.175") y la busco con: curl -s ifconfig.me - no sirve de nada aca

int main(int ac, char *av[]){
    int res,i;				// resultado de algunas funciones
    int ssock;             		// descriptor del socket del servidor
    int csock;             		// descriptor del socket de la coneccion
    struct sockaddr_in my_addr;	        // mi direccion
    struct sockaddr_in cl_addr;	        // direccion del cliente
    unsigned int len;			// tamanio de la direccion
    char buf[1024];			// buffer de recepcion

// verifica los argumentos de la linea de comandos
	if(ac !=2){
		printf("invocar %s <port_donde_servir>\n", av[0]);//msj de error que dice que argumentos hay que pasarle al programa
		return -1;
	}
// crea un socket del tipo stream (TCP) en el dominio INET (internet)
    ssock = socket(AF_INET, SOCK_STREAM, 0);
    /*
    SOCKET -> defino el protocolo de comunicación que utilizará el socket. puede ser TCP/IP o UDP
    me devuelve un socket, un file descriptor que es el que acepta conexiones de los clientes
    */
    if(ssock < 0){
    	perror(strerror(errno));
        return -1;
    }
// inicializa la direccion
    my_addr.sin_family = AF_INET;//familia del protocolo -> IPV4

    my_addr.sin_port = htons(atoi(av[1]));//puerto que elijo para el server

    my_addr.sin_addr.s_addr = htonl(INADDR_ANY); // es la direccion ip 0.0.0.0, permite que cualquier direccion ip se conecte al servidor
    //my_addr.sin_addr.s_addr = inet_addr("192.168.0.14");//si conozco la ip privada de la maquina en donde estoy sirviendo (ejecutando el programa server, puedo pasarle la direccion de esta manera)
    //cargo la direccion ip en el campo que corresponde de la estructura
    memset((void *) &(my_addr.sin_zero), '\0', 8);
    //memset me carga o me llena una estructura o una parte de memoria con lo que yo le pida. acá lleno de ceros o de nulls un campo de la estructura del server, longitud del campo = 8

// asigna la direcion al socket 
    res = bind(ssock, (struct sockaddr *)&my_addr, sizeof(my_addr));
//duda, por que castea a tipo (struct sockaddr *) si es de sockaddr_in???? por como está declarada

    /*
    BIND -> es una llamada al sistema operativo, le paso los datos que cargue en la estructura. 
    le informo que puerto voy a utilizar y que redireccione todo lo que llega a ese puerto en particular
    asocia el socket a un determinado puerto de la maquina
    */

    if(res < 0){
    	perror(strerror(errno));
        return -1;
    }
// muestra la direccion y el puerto. Cuidado de convertir entre los formatos network y host
    printf(" sirviendo en %s:%d ...\n", inet_ntoa(my_addr.sin_addr), ntohs(my_addr.sin_port));

// espera conexiones entrantes
    listen(ssock, 5);
/*
LISTEN -> prepara al socket para recibir conexiones. ese 5 representa la cantidad de conexiones que tengo en espera
*/

    //hay dos bucles while (1)
    //el primero es el que acepta conecciones, por eso la funcion accept esta dentro de este
    //el segundo es el que interactura entre la comunicacion entre cliente y server
    while(1){
// acepta la conexion entrante
        len = sizeof(cl_addr);
        csock = accept(ssock, (struct sockaddr *)&cl_addr, &len);

        /*
        ACCEPT -> accept es la funcion bloqueante, el programa espera conexiones del cliente 
        me devuelve otro socket, tmb un file descriptor, pero este hace referencia a la conexion que se estableció con el cliente c¿que se conectó 
        */

        if(csock < 0){
            perror(strerror(errno));
            return -1;
        }
        printf(" conectado desde %s:%d ...\n", inet_ntoa(cl_addr.sin_addr), ntohs(cl_addr.sin_port));//imprimo desde donde se conectan

// hasta recibir un mensaje 'chau!'
        while(1){

            //EL SERVER COMIENZA LA CONVERSACIÓN LEYENDO LO QUE LE MANDA EL CLIENTE

            memset(buf, 0, sizeof(buf));	// limpia el buffer de recepcion (lo llena con ceros)

            read(csock, buf, sizeof(buf));  	// lee el mensaje y lo almacena en buf

            printf("--- %s\n", buf); //imprimo buf, lo recibido

            if(!strcmp(buf,"chau!"))            // si recibe "chau!"  desde el cliente cierra la conexion con ese cliente solamente pero puede seguir recibiendo otras conexiones de clientes
            //strcmp me va a devolver 0 xq ambas cadenas son exactamente iguales y no hay diferecia entre lod caracteres
            //me devuelve 0, pero como tiene el ! supongo que lo invierte y por eso entra 
                break;
                //los break me sacan del while 

            if(!strcmp(buf,"cerrar!")){         // si recibe "cerrar!" cierra la conexion con ese cliente y tmb la conexion con el servidor, cierra los dos sockets
// cierra el socket del servidor
                close(ssock);//da por terminada la comunicacion, cierra el socket del servidor y sale del programa con un return, ni siquiera con un break
                return 0;
            }
            printf(">>> ");
            fgets(buf,sizeof(buf),stdin);       // lee respuesta del teclado
            for (i=0;buf[i]!='\0';i++){         // lo uso para buscar el valor de i donde está el null
            }     
            buf[i-1]='\0';      // elimino el salto de linea que escribió en nombre corriendo el null
            write(csock, buf, strlen(buf)+1);   // envia respuesta
        }
// cierra la conexion
        close(csock);//cierro el segundo socket, el de la conexion con el cliente debido al break anterior

    }//sube y se conecta nuevamente con otro cliente con la funcion accept
// cierra el socket del servidor
    close(ssock);
    return 0;
}
