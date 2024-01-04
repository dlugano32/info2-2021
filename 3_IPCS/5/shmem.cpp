#include "shmem.h"
#include <iostream>
using namespace std;

ShMem::ShMem(char *p, char a, int tam, bool destroy) :Ipcs(p, a ,destroy) //En ipcs genero la llave
{
    size=tam;
    conectar(llave);    //Me conecto
}

bool ShMem::conectar(key_t llave_l)
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

    }

    return aux;
}

bool ShMem::escribir(void *msg, int longitud, int inicio) const
{
    bool aux=false;

    if(longitud<=size && inicio<size)
    {

           for(int i=0, j=inicio; i<longitud-inicio; i++, j++)
           {
                buffer[i]=*( (char*) msg + j );    //lo recorre byte a byte, por eso uso una variable char, independientemente del dato
           }
           aux=true;
    }

    return aux;
}

int ShMem::leer(void *msg, int longitud, int inicio) const
{
    int i=0, j=0;

    if(longitud<=size && inicio<size)
    {
       for(i=0, j=inicio; i<longitud-inicio; i++, j++)
        {
            *( (char*)msg + j)=buffer[i];    //lo recorre byte a byte, por eso uso una variable char, independientemente del dato
        }
    }

    return i;
}

ShMem::~ShMem()
{
    if(borrar)
    {
        shmdt(buffer);  //Desvinculo este puntero con la shared memory (no libera memoria esta funcion)
        shmctl(id, IPC_RMID, nullptr);   //Libero la memoria utilizada por el ipc
        cout<<"Recursos liberados"<<endl;
    }
}
