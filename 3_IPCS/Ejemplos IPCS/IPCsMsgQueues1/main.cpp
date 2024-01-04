#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <errno.h>
//Ejemplo pensado para hacer un proceso principal y un thread.
//Si hago mas threads la idea es ver que ya no hay mensajes en la cola para recibir
#define MENSAJE		"Hola Mundo"
#define ERROR		-1

struct mymsgbuf {
    long	type;
    char	*str;
};

key_t 		llave;
int		cola_id;
char 		cadena[] = MENSAJE;
pid_t		pid;

int main ( void )
{
    struct mymsgbuf	mensaje;

    mensaje.type = 1;
    mensaje.str = cadena;

    //Obtengo la llave para generar un IPC
    if ( (llave = ftok("." , 'a')) == ERROR )
    {
        perror ("\nError ftok\n");
        return (1);
    }

    printf("\nLlave generada: %d\n",llave );

    //Genero mi cola de mensajes:
    if ( (cola_id = msgget( llave, IPC_CREAT | 0666 )) == ERROR )
    {
        perror ("\nError msgget\n");
        return (1);
    }

    printf("\nId de la cola: %d\n",cola_id);

    //Genero un proceso separado:
    if ( ( pid = fork() ) == ERROR )
    {
        perror ("\nError fork\n");
        return (1);
    }

    //El hijo manda un mensaje:
    if ( !pid )
    {
        //Pongo un mensaje en la cola de mensajes:
        if ( msgsnd ( cola_id , (struct msgbuf *) &mensaje , sizeof(struct msgbuf) , IPC_NOWAIT ) == ERROR )
            perror ("\nError msgsnd\n");
        else
            printf("\nHijo: Mensaje enviado\n");
    }
    else
    {

        sleep(1);
        wait (NULL);
        if ( msgrcv ( cola_id , (struct msgbuf *) &mensaje , sizeof ( struct msgbuf ) , 1 , 0 ) == ERROR )
            perror ("\nError msgrcv\n");
        else
            printf("\nPadre: Mensaje recibido: %s\n" , mensaje.str);

        //if ( msgctl(cola_id,IPC_RMID,NULL) == ERROR )
          //  perror ("\nError msgctl\n");

    }

    return (0);
}
