#include "shsem.h"
#include <iostream>
using namespace std;

int ShSem::indc=0;
bool ShSem::first_t=true;

ShSem::ShSem(char *p, char a, int tam, bool destroy) :Ipcs(p,a,destroy) //En ipcs genero la llave
{
    size=tam;
    conectar(p,a);    //Me conecto
}

bool ShSem::conectar(char *p,char a)
{
    bool aux=true;

    if(llave==-1)
    {
        if( generateKey(p,a) ==false )
        {
            cout<<"No se pudo crear la llave"<<endl;
            return false;
        }
    }

    if( ( id=shmget(llave, size, IPC_CREAT | 0666) ) <0 ) //Creo el ipc
    {
        perror("\nError shmget");
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
            if( (id_sem=semget(llave, 1, IPC_CREAT | 0666) )< 0)    //Creo el semaforo
            {
                   id=-1;
                   perror("\nError semget");
                   aux=false;
            }
            else
            {
                conectado=true;

                if(first_t)
                {
                    first_t=false;
                    LiberarShMem(); //Ya que quiero que el sem_op empieze con 1
                }
            }
        }
    }
    return aux;
}

void ShSem::bloquearShMem() const
{
    sembuf sem;

    sem.sem_num=0;
    sem.sem_op=-1;
    sem.sem_flg=0;//Se queda bloqueado esperando a poder acceder al recurso si esta esta siendo utilizado por otro proceso


    if( semop( id_sem, &sem , 1) == 0 )   //Siempre se trabaja con 1 semaforo
        cout<<"ShMem protegida"<<endl;
    else
        cout<<"Error-bloquearShMem()"<<endl;
}

void ShSem::LiberarShMem() const
{
    sembuf sem;

    sem.sem_num=0;
    sem.sem_op=1;
    sem.sem_flg=IPC_NOWAIT;

    if( semop( id_sem, &sem , 1) == 0)   //Siempre se trabaja con 1 semaforo
        cout<<"ShMem liberada"<<endl;
    else
        cout<<"Error-LiberarShMem()"<<endl;
}

bool ShSem::escribir(void *msg, int tam, int inicio) const
{
    bool aux=false;

    if(conectado && (size>inicio))
    {
        bloquearShMem();

        for(int i=0, j=inicio; i<tam; i++, j++, indc ++)    //Recordar que inicio es a partir de que byte voy a empezar a escribir
        {
             buffer[j]=*( (char*) msg + i );    //lo recorre byte a byte, por eso uso una variable char, independientemente del dato
        }

        LiberarShMem();
        aux=true;
    }

    return aux;
}

int ShSem::leer(void *msg, int tam, int inicio) const
{
    int i=0, j=0;

    if(conectado && (size>inicio))
    {
        bloquearShMem();

       for(i=0, j=inicio; i<tam; i++, j++, indc ++) //Recordar que inicio es a partir de que byte voy a empezar a escribir
       {
            *( (char*)msg + i)=buffer[j];    //lo recorre byte a byte, por eso uso una variable char, independientemente del dato
       }

        LiberarShMem();
    }
    return i;
}

ShSem::~ShSem()
{
    shmdt(buffer);  //Desvinculo este puntero con la shared memory (no libera memoria esta funcion)
    if(borrar)
    {
        shmctl(id, IPC_RMID, nullptr);   //Libero la memoria utilizada por el ipc
        semctl(id_sem, 0, IPC_RMID);    //Libero el semaforo
        cout<<"Recursos liberados"<<endl;
    }
}
