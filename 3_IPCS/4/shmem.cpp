#include "shmem.h"
#include <iostream>
using namespace std;

ShMem::ShMem(char *p, char a, int tam, bool destroy) :Ipcs()
{
    id=-1;
    borrar=destroy;
    size=tam;

    if(p!=nullptr)
    {
        if( ( llave=ftok(p , a) ) <0)  //p es el path de files donde voy a crear el IPC
            perror ("\nError ftok\n");
        else
        {
            if( ( id=shmget(llave, tam, IPC_CREAT | 0666) <0) )
                perror("\nError msgget");

            buffer=(char *)shmat(id, nullptr, 0);       //attacheo la memoria compartida a mi variable buffer //Obtengo un puntero que indique la posición de comienzo de mi bloque de memoria compartida

            if(buffer == (char *)-1 )
                perror("\nErrpr shmat");

        }
    }
}

bool ShMem::conectar(char *p , char a, int tam)
{
    bool aux=false;
    id=-1;

    if(p!=nullptr)
    {
        if( ( llave=ftok(p , a) ) <0)
            perror ("\nError ftok\n");
        else
        {
            if( ( id=shmget(llave, tam, IPC_CREAT | 0666) <0) )
                perror("\nError msgget");

            buffer=(char *)shmat(id, nullptr, 0);   //attacheo la memoria compartida a mi variable buffer

            if(buffer == (char *)-1 )
                perror("\nErrpr shmat");

            aux=true;

        }
    }

    return aux;
}

bool ShMem::escribir(void *msg, int longitud, int inicio) const
{
    bool aux=false;

    if(longitud<size && inicio<size)
    {
           for(int i=0; i<longitud-inicio; i++, inicio++)
           {
                buffer[i]=((char*) msg)[inicio];
           }
           aux=true;
    }

    return aux;
}

int ShMem::leer(char *buf, int longitud, int inicio) const
{
    int i=0;

    if(longitud<size && inicio<size)
    {
           for(i=0; i<longitud-inicio; i++, inicio++)
           {
                buf[i]=buffer[inicio];
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
