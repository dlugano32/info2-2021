#ifndef LISTA_H
#define LISTA_H

#include "persona.h"
#include <iostream>
using namespace std;

class Lista
{
    private:
        struct nodo
        {
            Persona dato;
            nodo *next; //En la ultima posicion apunta a NULL
        };

        nodo *comienzo;
        int tam;

    public:
    Lista();
    ~Lista();

    Lista& AgregarNodoFinal( const Persona &);
    Lista& AgregarNodoPrincipio(const Persona &);
    Lista& EliminarNodo(const Persona &);
    int BuscarNodo(const Persona &);
    int getTam() { return tam; };

    Lista& operator+= (const Persona &);
    Lista& operator-= (const Persona &);
    Lista& operator+= (const Lista &);
    Persona& operator [](int posicion);

    friend ostream & operator << (ostream &, const Lista &);

};

ostream & operator << (ostream &, const Lista &);
#endif // LISTA_H
