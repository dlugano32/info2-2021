#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>


int main(int ac, char *av[]){
    int res,i;				// resultado de algunas funciones
    int sock;             		// descriptor del socket
    struct sockaddr_in server;          // direccion del servidor
    struct hostent *hp;			// host entity information (datos del host donde estoy corriendo)
    char buf[1024];			// buffer de recepcion

// verifica los argumentos de la linea de comandos
    if(ac != 3){
        printf("invocar %s <ip_o_nombre_servidor> <puerto_servidor>\n", av[0]);//msj de error si no se ingresan los datos necesarios 
        return -1;
    }
// crea un socket del tipo stream (TCP) en el dominio INET (internet)
    sock = socket(AF_INET, SOCK_STREAM, 0 );
    if(sock < 0){
    	perror(strerror(errno));
        return -1;
    }
// inicializa la direccion
    server.sin_family = AF_INET;//cargo la estructura del server al que me voy a conectar. esta estructura la tengo que pasar en la función connect()
    server.sin_port = htons(atoi(av[2]));
// busca la direccion del servidor

    hp = gethostbyname(av[1]);//con esta función busco la ip del server al que me quiero conectar. si le paso la ip de loopback (127.0.0.1), encunetra la ip del server
    //me devuelve una estructura del tipo "hostent"
    if(!hp){
    	perror(strerror(errno));
        return -1;
    }
// copia la direccion IP
    memcpy(&server.sin_addr, hp->h_addr, hp->h_length);//copio al primer parámetro ("&server.sin_addr") lo del segundo parámetro, cuya longitud es la del tercero
    //la funcion  gethostbyname me devuelve la direccion del server al que me quiero conectar, pero dentro de una estructura del tipo "hostent".
    // Por lo tanto utilizo esta función para pasar la direc ip a la estructura del tipo "sockaddr_in" que necesito pasarle a la función connect
    //copio una estructura entera xq el campo sin.addr es una estructura tmb

// se conecta con el servidor
    res = connect(sock, (struct sockaddr *) &server, sizeof(server));
    //con esta funcion establesco la conexion cliente - servidor, le paso como datos el socket mio (del cliente, el de la fucion socket () inicial) y los datos del server al que me voy a conectar

    if(res < 0){
    	perror(strerror(errno));
        return -1;
    }

    while(1){//un solo bucle while (1), simplemente de la conexión que se forma cliente - servidor

        //EL CLIENTE ARRANCA LA CONVERSACION ESCRIBIENDO Y EL SERVER LEYENDO

        printf(">>> ");
        fgets(buf,sizeof(buf),stdin);                          // lee respuesta del teclado
        for (i=0;buf[i]!='\0';i++){         // lo uso para buscar el valor de i donde está el null
        }     
        buf[i-1]='\0';      // elimino el salto de linea que escribió en nombre corriendo el null

        write(sock, buf, strlen(buf)+1);    // envia mensaje
        if(!strcmp(buf, "chau!"))           // si envie (yo, el cliente) "chau!", cierra la conexion
            break;
        if(!strcmp(buf, "cerrar!"))         // si envie "cerrar!", cierra la conexion
            break;

        memset(buf, 0, sizeof(buf));	    // limpia el buffer para prepararlo para la recepcion
        read(sock, buf, sizeof(buf));       // lee los bytes recibidos
        printf("--- %s\n", buf);            // muestra el mensaje recibido
    }
    close(sock);			    // cierra el socket

    return 0;
}

/*
ACLARACION -> en este ejemplo no se utiliza bind () en el programa cliente ya que se deja a que el sistema operativo le asigne al cliente libremente el puerto que tenga disponible para realizar la conexion. no se le deja atornillado un puerto en especial al cliente xq a veces tardan en ser liberados.
supongo que el server sabe desde que direccion de memoria se estan conectando por la información que viene montada sobre el protocolo TCP/IP en IPV4
en un programa (que perdi : (((((( ) había hecho bind con el cliente para poder fijarle un puerto, pero dsps tardaba en liberarlo.
*/