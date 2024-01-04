#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include <errno.h>

#define MENSAJE		"Hola Mundo"
#define LONG_MENSAJE	15
#define ERROR		-1
#define PEDIR_CTRL	-1
#define LIBERAR		1

void *LeeMensaje (void * );

key_t 		llave;
int         shm_id;
char 		cadena[LONG_MENSAJE] 	= MENSAJE;
char 		*buffer 		= NULL;

int main ( void )
{
    pid_t		pid;
    int i;

    //Obtengo la llave para generar un IPC
    llave = ftok("." , 'a');
    if ( llave  == ERROR )
    {
        perror ("\nError ftok\n");
        return (1);
    }

    printf("\nLlave generada: %d\n",llave );

    //Genero mi shared memory IPC:
    shm_id = shmget( llave , LONG_MENSAJE , IPC_CREAT | 0666 );
    if (  shm_id == ERROR )
    {
        perror ("\nError shmget\n");
        return (1);
    }

    printf("\nId de la shared memory: %d\n",shm_id);

    //Obtengo un puntero que indique la posición de comienzo de mi bloque de memoria compartida:
    buffer = (char *) shmat ( shm_id , NULL , 0 );

    if ( buffer == (char *)-1 )
    {
        perror ("\nError shmat\n");
        return (1);
    }

    printf("\nPrincipal: Buffer de memoria creado y attached a buffer, direccion %p\n",buffer);

    if ( ( pid = fork() ) == ERROR )
    {
        perror ("\nError fork\n");
        return (1);
    }

    //El padre pone un mensaje en la memoria, los hijos la leen:
    if (pid)
    {
        //Pongo un mensaje en la memoria compartida:
        for ( i = 0 ; i < LONG_MENSAJE ; i++ )
            buffer[i] = cadena[i];

        printf("\nPrincipal: Mensaje en la memoria\n");

        wait (NULL);

        //Libero el recurso:
        shmctl(shm_id,IPC_RMID,NULL);
    }
    else
    {
        //Espero para que el padre escriba en memoria:
        sleep(1);

        printf("\nHijo: Mensaje recibido: %s",buffer);
    }

    shmdt(buffer);

    return (0);
}
