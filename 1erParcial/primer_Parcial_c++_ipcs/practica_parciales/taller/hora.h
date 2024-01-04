#ifndef HORA_H
#define HORA_H

#include <iostream>
using namespace std;

class Hora
{
    private:
        int hora,min;
    public:
        Hora();// inicializa en 0,0
        Hora(int,int=0);

        friend ostream & operator << (ostream &, const Hora&);
    // agregar mas métodos si considera que hace falta
};

ostream & operator <<(ostream &, const Hora&);
#endif // HORA_H
