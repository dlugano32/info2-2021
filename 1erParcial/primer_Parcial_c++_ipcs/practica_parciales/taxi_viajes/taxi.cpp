#include "taxi.h"

Taxi::Taxi() :Patente("0") , ApeNomChofer("NN")
{
   Licencia=0;
}

Taxi::Taxi(string Pat, long lic, string ApeNom) : Patente(Pat) , ApeNomChofer(ApeNom)
{
    Licencia=lic;
}

Taxi::Taxi(const Taxi &T) :Patente(T.Patente) , ApeNomChofer(T.ApeNomChofer)
{
    Licencia=T.Licencia;
}

Taxi::~Taxi()
{

}

void Taxi::set_datos(string Pat, long lic, string ApeNom)
{
    Patente=Pat;
    ApeNomChofer=ApeNom;
    Licencia=lic;
}

Taxi &Taxi::operator =(Taxi &T)
{
    T.set_datos(Patente, Licencia, ApeNomChofer);

    return *this;
}

ostream& operator << (ostream& c, Taxi& T)
{
    c<<"Nombre: "<<T.ApeNomChofer<<endl<<"Patente: "<<T.Patente<<endl;
    c<<"Licencia: "<<T.Licencia<<endl;

    return c;
}


