#include "taller.h"

const string Taller::Tarea[4]={"C_Bujias","Afinación","Embrague","C_Amortiguadores"};
const int Taller::Costo[4]={2000,5000,8800,3500};

Taller::Taller() : Marca("SIN DATOS"), Modelo("SIN DATOS"), Patente("SIN DATOS"), h()
{

}

Taller::Taller(const string & marca, const string & mod, const string &pat, int hor, int min)
: Marca(marca), Modelo(mod), Patente(pat), h(hor,min)
{

}

ostream& operator<< (ostream& c, Taller& T)
{
    c<<"\t\tPATENTE: "<<T.Patente<<endl;
    c<<"Marca: "<<T.Marca<<endl<<"Modelo: "<<T.Modelo<<endl;
    c<<"Hora ingreso: "<<T.h<<endl;

    return c;
}
