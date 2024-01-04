#include "persona.h"

Persona::Persona():Nombre("N") , Apellido("N")
{
    dni=0;
}

Persona::Persona(const string &name, const string &ape, long id) : Nombre(name) , Apellido (ape)
{
    dni=id;
}

Persona::Persona(const Persona &P): Nombre(P.Nombre) , Apellido(P.Apellido)
{
    dni=P.dni;
}

Persona &Persona::operator =(const Persona &P)
{
    Nombre=P.Nombre;
    Apellido=P.Apellido;
    dni=P.dni;

    return *this;
}

bool Persona::operator ==(const Persona &P)
{
    bool aux=false;

    if( (Nombre==P.Nombre) && (Apellido==P.Apellido) && (dni==P.dni) )
        aux=true;

    return aux;
}

ostream & operator <<(ostream &c, const Persona &P)
{
    c<<"Nombre :"<<P.Nombre<<endl<<"Apellido: "<<P.Apellido<<endl<<"DNI: "<<P.dni<<endl;
    return c;
}


