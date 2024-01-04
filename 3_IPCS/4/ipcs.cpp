#include "ipcs.h"

Ipcs::Ipcs()
{
    llave=0;
    borrar=false;
}

key_t Ipcs::GetKey() const
{
    return llave;
}

void Ipcs::SetBorrar(bool destroy)
{
    borrar=destroy;
}
