#include "ipcs.h"

Ipcs::Ipcs(char *p, char c, bool destroy)
{
    SetBorrar(destroy);
    generateKey(p,c);
}

Ipcs::Ipcs(key_t key, bool destroy)
{
    llave=key;
    SetBorrar(destroy);
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

key_t Ipcs::GetKey() const
{
    return llave;
}

void Ipcs::SetBorrar(bool destroy)
{
    borrar=destroy;
}
