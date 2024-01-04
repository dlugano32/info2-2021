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
int         shm_id, sem_id;
char 		cadena[LONG_MENSAJE] 	= MENSAJE;
char 		*buffer 		= NULL;

int main ( void )
{
    pid_t		pid;
    int i;
    struct sembuf operacion;

    //Obtengo la llave para generar un IPC
    llave = ftok("." , 'a');
    if ( llave  == ERROR )
    {
        perror ("\nError ftok\n");
        return (1);
    }

    printf("\nLlave generada: %d\n",llave );

    //Genero mi semaforo:
    sem_id = semget( llave, 1 , IPC_CREAT | 0666 );
    if (  sem_id == ERROR )
    {
        perror ("\nError semget\n");
        return (1);
    }

    printf("\nId del semaforo: %d\n",sem_id);

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

        //"Libero" el semaforo:
        operacion.sem_num = 0;
        operacion.sem_op = LIBERAR;
        operacion.sem_flg = 0;

        if ( ( semop( sem_id , &operacion , 1 ) ) == ERROR )
        {
            perror ("\nError semop\n");
            return (1);
        }

        printf("\nPrincipal: Recurso liberado\n");

        wait (NULL);

        //Libero los IPCs:
        shmctl(shm_id,IPC_RMID,NULL);
        semctl(sem_id,0,IPC_RMID);
    }
    else
    {
        //Pregunto si ya puedo leer el buffer:
        operacion.sem_num = 0;
        operacion.sem_op = PEDIR_CTRL;
        operacion.sem_flg = IPC_NOWAIT;

        semop( sem_id , &operacion , 1 );

        printf("\nHijo: Mensaje recibido: %s",buffer);

        //"Libero" el semaforo:
        operacion.sem_num = 0;
        operacion.sem_op = LIBERAR;
        operacion.sem_flg = 0;

        if ( ( semop( sem_id , &operacion , 1 ) ) == ERROR )
        {
            perror ("\nError semop\n");
            return (1);
        }

    }

    shmdt(buffer);

    return (0);
}
