#include "shsem.h"
#include <iostream>
using namespace std;

void ShSem::bloquearShMem() const
{
    sembuf sem;

    sem.sem_flg=0;  //Se queda bloqueado esperando a poder acceder al recurso si esta esta siendo utilizado por otro proceso
    sem.sem_op=-1;
    sem.sem_num=0;

    semop( id_sem, &sem , 1);   //Siempre se trabaja con 1 semaforo
}

void ShSem::LiberarShMem() const
{
    sembuf sem;

    sem.sem_flg=0;
    sem.sem_op=1;
    sem.sem_num=0;

    semop( id_sem, &sem , 1);   //Siempre se trabaja con 1 semaforo
}

ShSem::ShSem(char *p, char a, int tam, bool destroy) :Ipcs(p,a,destroy) //En ipcs genero la llave
{
    size=tam;
    conectar(llave);    //Me conecto
}

bool ShSem::conectar(key_t llave_l)
{
    bool aux=true;

    if( ( id=shmget(llave_l, size, IPC_CREAT | 0666) ) <0 ) //Creo el ipc
    {
        perror("\nError msgget");
        aux=false;
    }
    else
    {
        buffer=(char *)shmat(id, nullptr, 0);   //attacheo la memoria compartida a mi variable buffer

        if(buffer == (char *)-1 )
        {
            perror("\nErrpr shmat");
            aux=false;
        }
        else
        {
            if( (id_sem=semget(llave_l, 1, IPC_CREAT | 0666) )< 0)    //Creo el semaforo
            {
                   id=-1;
                   perror("\nError semget");
                   aux=false;
            }
        }
    }

    return aux;
}

bool ShSem::escribir(void *msg, int longitud, int inicio) const
{
    bool aux=false;

    if(longitud<=size && inicio<size)
    {
        bloquearShMem();

        for(int i=0, j=inicio; i<longitud-inicio; i++, j++)
        {
             buffer[i]=*( (char*) msg + j );    //lo recorre byte a byte, por eso uso una variable char, independientemente del dato
        }

        LiberarShMem();
        aux=true;
    }

    return aux;
}

int ShSem::leer(void *msg, int longitud, int inicio) const
{
    int i=0, j=0;

    if(longitud<size && inicio<size)
    {
        bloquearShMem();

           for(i=0, j=inicio; i<longitud-inicio; i++, j++)
           {
                *( (char*)msg + j)=buffer[i];    //lo recorre byte a byte, por eso uso una variable char, independientemente del dato
           }

        bloquearShMem();

    }

    return i;
}

ShSem::~ShSem()
{
    if(borrar)
    {
        shmdt(buffer);  //Desvinculo este puntero con la shared memory (no libera memoria esta funcion)
        shmctl(id, IPC_RMID, nullptr);   //Libero la memoria utilizada por el ipc
        semctl(id_sem, 0, IPC_RMID);    //Libero el semaforo
        cout<<"Recursos liberados"<<endl;
    }
}