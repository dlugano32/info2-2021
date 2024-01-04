#include "persona.h"

//Constructores

Persona::Persona() : nombre("NN"), apellido("NN")   //hago los constructores con lista inicializadora de manera de reutilizar los constructores ya hechos
{
    dni=0;
}

Persona::Persona(my_string name, my_string last_name, int d) : nombre(name), apellido(last_name)
{
    dni=d;
}

Persona::Persona(const Persona &P) : nombre(P.nombre), apellido(P.apellido)
{
    dni=P.dni;
}

//Metodos

void Persona::set_Persona(my_string name, my_string last_name, int d)
{
    set_nombre(name);
    set_apellido(last_name);
    set_dni(d);
}

void Persona::set_nombre(my_string name)
{
    nombre=name;
}

void Persona::set_apellido(my_string last_name)
{
    apellido=last_name;
}

void Persona::set_dni(int d)
{
    dni=d;
}

Persona &Persona::get_Persona()
{
    return *this;
}

my_string &Persona::get_nombre()
{
    return nombre;
}

my_string &Persona::get_apellido()
{
    return apellido;
}

int Persona::get_dni()
{
    return dni;
}

ostream & operator << ( ostream &c, const Persona & P)
{
    c<<"\""<<P.nombre<<"\",\""<<P.apellido<<"\","<<P.dni;

    return c;
}

