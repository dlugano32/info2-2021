#include "lote.h"
#include "vacuna.h"

Lote::Lote(unsigned int c)
{
    cant = c;
    p = c ? (new Vacuna[cant]) : nullptr;
}

Lote::Lote(const Lote &l)
{
    cant = l.cant;
    p = cant ? (new Vacuna[cant]) : nullptr;

    for(unsigned int i=0; i<cant; i++)
    {
        *(p+i)=*(l.p+i);
    }
}

Lote::~Lote()
{
    delete [] (p);
}

void Lote::setTempBatch(int t)
{
    for(unsigned int i=0; i<cant; i++)
    {
        ((*this)[i]).setTemp(t);
    }
}

int Lote::getBadVacs()
{
    unsigned int j = 0;
    for(unsigned int i=0; i<cant; i++)
    {
        if(!((*this)[i]).getEst())
        {
            j++;
        }
    }
    return j;
}

Lote & Lote::operator << (const Vacuna &v)
{
    unsigned int i=0;
    Vacuna * aux = new Vacuna [++cant];

    for(; i<(cant-1); i++)
    {
        aux[i]=p[i];
    }

    aux[i] = v;

    delete [] (p);

    p = aux;

    return *this;
}

unsigned int Lote::getCant() const
{
    return cant;
}

Vacuna *Lote::getVacs() const
{
    return p;
}

Vacuna & Lote::operator [] (unsigned int n)
{
    unsigned int aux = n;
    if(n>=cant)
    {
        aux = cant - 1;
    }
    return *((this->p)+aux);
}
