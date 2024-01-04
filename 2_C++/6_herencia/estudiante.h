#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "persona.h"

class Estudiante : public Persona
{

    private:

    unsigned int legajo;
    static int contador;

    public:
        Estudiante();
        Estudiante(my_string name, my_string last_name, int d, int legajo);
        Estudiante(const Estudiante&);

        friend ostream & operator << (ostream &c, const Estudiante& est);
};

ostream & operator << (ostream &c, const Estudiante& est);

#endif // ESTUDIANTE_H
