#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>

using namespace std;

class Persona
{
    private:
        string Nombre;
        string Apellido;
        long dni;

    public:
    Persona();
    Persona(const string & name, const string & ape, long );
    Persona(const Persona &);

    Persona& operator = (const Persona &);
    bool operator == (const Persona &);

    friend ostream & operator <<(ostream &, const Persona &);

};

ostream & operator <<(ostream &, const Persona &);

#endif // PERSONA_H
