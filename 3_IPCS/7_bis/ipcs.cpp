#include "ipcs.h"

bool Ipcs::conectado=false;

Ipcs::Ipcs()
{
    id=-1;
    llave=-1;
    conectado=false;
    borrar=false;
}

Ipcs::Ipcs(char *p, char c, bool destroy)
{
    SetBorrar(destroy);
    generateKey(p,c);
    conectado=false;
}

bool Ipcs::generateKey(char *path, char a)
{
    bool aux=false;

    if( ( llave=ftok(path , a) ) <0)
    {
        perror ("\nError ftok\n");
        llave=-1;
    }
    else
        aux=true;

    return aux;
}

int Ipcs::GetID() const
{
    return id;
}

key_t Ipcs::GetKey() const
{
    return llave;
}

void Ipcs::SetBorrar(bool destroy)
{
    borrar=destroy;
}
