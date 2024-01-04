#ifndef PILA_H
#define PILA_H

#include <iostream>
using namespace std;

typedef struct dato
{
    int duracion_viaje;
    int precio;

}DATO;

typedef struct nodo
{
    DATO d;
    struct nodo*next;

}NODO;

class Pila
{
    protected:
        NODO *H;

        bool vacio (void) {return H==nullptr; }

    public:
        Pila();
        ~Pila();
        bool push (DATO &);
        bool pop (DATO &);
        void borrarPila();

        Pila& operator = (const Pila& P);
        DATO &operator =(const DATO &D);

        friend ostream & operator << (ostream &, Pila &);
};

ostream & operator << (ostream &, Pila &);

#endif // PILA_H
