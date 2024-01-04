#include "viajes.h"

Viajes::Viajes(): Taxi(), P()
{

}

Viajes::~Viajes()
{
    P.borrarPila();
}

Viajes::Viajes(string pat, long lic, string ApeNom, int duracion, int precio) : Taxi(pat, lic, ApeNom), P()
{
    set_viaje(duracion, precio);
}

void Viajes::set_viaje(int duracion, int precio) //En este caso la pila ya esta instanciada
{
    DATO d;
    d.duracion_viaje=duracion;
    d.precio=precio;
    P.push(d);
}

void Viajes::liquidacion(float *ganancia_agencia, float *ganancia_chofer)   //Tengo en cuenta que los parametros de entrada tienen un valor razonable seteado, por ejemplo lo que tienen en la cuenta bancaria cada uno
{
    DATO d;
    while(P.pop(d))
    {
        *ganancia_agencia+=(float)d.precio*0.3;
        *ganancia_chofer+=(float)d.precio*0.7;
    }

    //La pila se borra de ir haciendo pop
}

ostream & operator << (ostream & c, Viajes & V)
{
    c<< (Taxi &) V;

    c<<V.P;

    return c;
}

