#include "lote.h"
#include "vacuna.h"
#include "cargamento.h"

Cargamento::Cargamento(): Lote(), fabricante("-"), destino("-")
{
}

Cargamento::Cargamento(string f, string d):Lote (), fabricante(f), destino(d)
{

}

Cargamento& Cargamento::operator << (const Lote& L)
{
    cant+=L.getCant();

    Vacuna * aux = new Vacuna [cant];

    for(unsigned int i=0; i < ( cant-L.getCant() ) ; i++)
    {
        aux[i]=p[i];
    }

    for (unsigned int i=cant-L.getCant(), j=0 ; i<cant ; i++, j++)
    {
        aux[i]=(L.getVacs())[ j ];
    }

    delete [] (p);

    p = aux;

    return *this;
}

Cargamento& Cargamento::operator << (const Vacuna& vac)
{
    Lote::operator <<(vac);

    return *this;
}

ostream& operator << (ostream &out, const Cargamento& c)
{
    out<<"Fabricante: "<<c.fabricante<<endl;
    out<<"Destino: "<<c.destino<<endl;

    for(unsigned int i=0; i<c.cant; i++)
    {
       out<<(c.p)[i]<<endl;
    }

    return out;
}
