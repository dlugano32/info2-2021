#include "estudiante.h"

Estudiante::Estudiante(): Persona("NN", "NN", 0)
{
    legajo=0;
}

Estudiante::Estudiante(my_string name, my_string last_name, int d, int l): Persona(name,last_name,d)
{
    legajo=l;
}

Estudiante::Estudiante(const Estudiante & est)  :Persona(est.nombre, est.apellido, est.dni)
{
    legajo=est.legajo;
}

ostream & operator << (ostream &c, const Estudiante& est)
{
    c<<"Estudiante E1 (";
    c<< (Persona &) est;    //Convoco al operador de impresion de Persona
    c<<","<<est.legajo<<")"<<endl;

    return c;
}
