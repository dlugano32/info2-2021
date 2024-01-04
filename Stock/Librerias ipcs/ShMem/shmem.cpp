#include "shmem.h"
#include <iostream>
using namespace std;

int ShMem::indc=0;

ShMem::ShMem(char *p, char a, int tam, bool destroy) :Ipcs(p, a ,destroy) //En ipcs genero la llave
{
    size=tam;
    conectar(p,a);    //Me conecto
}

bool ShMem::conectar(char *p, char a)
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
            perror("\nError shmat");
            aux=false;
        }
        else
        {
            conectado=true;
        }
    }

    return aux;
}

bool ShMem::escribir(void *msg, int tam, int inicio) const
{
    bool aux=false;

    if(conectado && (size>inicio))
    {
           for(int i=0, j=inicio; i<tam; i++, j++, indc++)
           {
                buffer[j]=*( (char*) msg + i );    //lo recorre byte a byte, por eso uso una variable char, independientemente del dato
           }
           aux=true;
    }
    return aux;
}

int ShMem::leer(void *msg, int tam,int inicio) const
{
    int i=0, j=0;

    if(conectado && (size>inicio))
    {
       for(i=0, j=inicio; i<tam; i++, j++, indc++)
        {
            *( (char*)msg + i)=buffer[j];    //lo recorre byte a byte, por eso uso una variable char, independientemente del dato
        }
    }
    return i;
}

ShMem::~ShMem()
{
    shmdt(buffer);  //Desvinculo este puntero con la shared memory (no libera memoria esta funcion)
    if(borrar)
    {
        shmctl(id, IPC_RMID, nullptr);   //Libero la memoria utilizada por el ipc
        cout<<"Recursos liberados"<<endl;
    }
}
