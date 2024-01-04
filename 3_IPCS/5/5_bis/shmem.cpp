#include "shmem.h"
#include <iostream>
using namespace std;

ShMem::ShMem(char *p, char a, int tam, bool destroy) :Ipcs(p, a ,destroy) //En ipcs genero la llave
{
    size=tam;
    conectar(llave);    //Me conecto
}

bool ShMem::conectar(key_t llave)
{
    bool aux=true;

    if( ( id=shmget(llave, size, IPC_CREAT | 0666) ) <0 ) //Creo el ipc
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

bool ShMem::escribir(void *v, int cant) const
{
    bool aux=false;
    int tam= cant*sizeof(struct sensores)+4; //El +4 es por el entero que voy a poner al principio int=4bytes

    if(tam<=size)
    {
        *(buffer+0)=(char)tam;

           for(int i=4; i<tam ; i++)
           {
                buffer[i]=*( (char*)v +i -4);
                //lo recorre byte a byte, por eso uso una variable char, independientemente del dato//  el 4 por el entero que pongo primero
           }
           aux=true;

    }

    return aux;
}

int ShMem::leer(void *msg, int longitud) const
{
    int i=0;

    for(i=0; i<longitud; i++)
    {
        *( (char*)msg + i)=buffer[i];    //lo recorre byte a byte, por eso uso una variable char, independientemente del dato
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
