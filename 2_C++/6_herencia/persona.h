#ifndef PERSONA_H
#define PERSONA_H

#include "my_string.h"

class Persona
{
    protected:
            my_string nombre;
            my_string apellido;
            int dni;
    public:

            Persona();
            Persona(my_string name, my_string last_name, int d);
            Persona( const Persona & P);

            void set_Persona(my_string name, my_string last_name, int d);
            void set_nombre(my_string name);
            void set_apellido(my_string last_name);
            void set_dni(int d);
            Persona& get_Persona(void);
            my_string& get_nombre(void);
            my_string& get_apellido(void);
            int get_dni(void);

            friend ostream & operator << ( ostream &c, const Persona & P);
};

ostream & operator << ( ostream &c, const Persona & P);

#endif // PERSONA_H
