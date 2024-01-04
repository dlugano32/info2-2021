#include "pila.h"

Pila::Pila()
{
    H=nullptr;
}

Pila::~Pila()
{
    borrarPila();
}

bool Pila::push(DATO &D)
{
    bool ret=true;

    NODO *nuevo =new NODO;
    if(nuevo==nullptr)
        ret=false;

    nuevo->d=D;
    nuevo->next=nullptr;

    if(H==nullptr) //Lista vacia
    {
        H=nuevo;
    }
    else
    {
        NODO* aux=H;

        while(aux->next!=nullptr)
        {
            aux=aux->next;
        }

        aux->next=nuevo;
    }

    return ret;
}

bool Pila::pop(DATO &D) //Le paso por referencia un DATO para guardar el valor que elimino de la cola
{
    bool ret=false;

    if(H!=nullptr)
    {
        NODO *aux=H;

        D=aux->d;   //Guardo el dato

        H=aux->next;    //Ahora H es el nodo siguiente
        delete aux;     //Borro lo que anteoriormente era H
        ret=true;
    }

    return ret;
}

void Pila::borrarPila()
{
    while(H!=nullptr)
    {
        NODO *aux=H;
        H=aux->next;
        delete aux;
    }
}

DATO & Pila::operator =(const DATO &D)
{
    H->d.duracion_viaje=D.duracion_viaje;
    H->d.precio=D.precio;

    return H->d;
}

Pila & Pila::operator =(const Pila &P)
{
    borrarPila();   //Elimino todos las posiciones de memoria que tenia reservada antes

    H=nullptr;

    for(NODO *aux=P.H; aux!=nullptr; aux=aux->next)
        push(aux->d);

    return *this;
}

ostream & operator << (ostream &c, Pila &P)
{
    int i=0;

    for(NODO *aux=P.H; aux!=nullptr; aux=aux->next, i++)
    {
        c<<"Viaje N°"<<i+1<<endl;
        c<<"Duracion :"<<aux->d.duracion_viaje<<endl;
        c<<"Valor :"<<aux->d.precio<<endl;
    }

    return c;
}
