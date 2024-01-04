#include "lista.h"

Lista::Lista()
{
    comienzo=nullptr;   //Usar ambos es redundante
    tam=0;
}

Lista::~Lista()
{
    nodo *aux=comienzo;

    for(int i=0; i<tam; i++, aux=aux->next)
        EliminarNodo(aux->dato);
}

Lista &Lista::AgregarNodoFinal(const Persona & P)
{
    nodo * nuevo =new nodo;

    nuevo->next=nullptr;    //El nuevo nodo, como lo voy a poner ultimo, apunta a null
    nuevo->dato=P;

    if(tam==0)
        comienzo=nuevo;
    else
    {
        nodo *aux=comienzo;

        for(int i=0; i<tam-1; i++)
            aux=aux->next;      //Recorro la lista hasta llegar al ultimo nodo

        aux->next=nuevo;
    }
    tam++;

    return *this;
}

Lista &Lista::AgregarNodoPrincipio(const Persona &P)
{
    nodo * nuevo =new nodo;

    nuevo->dato=P;

    if(tam==0)
    {
        nuevo->next=nullptr;
        comienzo=nuevo;
    }
    else
    {
        nodo *aux=comienzo;
        comienzo=nuevo;
        nuevo->next=aux;
    }

    tam++;

    return *this;
}

int Lista::BuscarNodo(const Persona &P)
{
    int retorno=-1;

    if(tam != 0)
    {
        nodo *aux=comienzo;

        for(retorno=0; retorno<tam; retorno ++, aux=aux->next)
        {
            if(aux->dato==P)
                break;
        }

        if(retorno ==tam)
            retorno =-1;
    }

    return retorno;
}

Lista &Lista::operator+=(const Persona &P)
{
    AgregarNodoFinal(P);

    return *this;
}

Lista &Lista::operator-=(const Persona &P)
{
    EliminarNodo(P);

    return *this;
}

Lista& Lista::operator+= (const Lista &L1)
{
    nodo *aux=L1.comienzo;

    for(int i=0; i<L1.tam; i++, aux=aux->next)
        AgregarNodoFinal(aux->dato);

    return *this;
}

Lista &Lista::EliminarNodo(const Persona &P)
{
    int nro_nodo=BuscarNodo(P);

    if(nro_nodo!=-1)
    {
        nodo *aux=comienzo;

        if(nro_nodo == 0)
        {
            comienzo=aux->next;     //Seria como comienzo=comienzo->next //osea, cambio el puntero comienzo al siguiente

            delete aux;
        }
        else
        {
            nodo* borrar;

            for(int i=0; i<nro_nodo-1; i++)
                aux=aux->next;

            //Cuando llego a nro_nodo-1 lo guardo en aux
            borrar=aux->next;   //El nodo a borrar es el siguiente a nro_nodo-1
            aux->next=borrar->next; //Osea, concateno el nodo que esta antes del que quiero borrar con el que esta despues

            delete borrar;
        }

        tam--;
    }

    return *this;
}


Persona &Lista::operator [](int posicion)
{
    static Persona err("N", "N", 0);
    Persona &retorno=err;

    if(posicion < tam)
    {
        nodo * aux=comienzo;

        for(int i=0; i< posicion; i++)
            aux=aux->next;

        retorno=aux->dato;
    }

    return retorno;
}

ostream & operator << (ostream & c,const Lista & L)
{
    Lista::nodo *aux=L.comienzo;

    for(int i=0; i<L.tam; i++, aux=aux->next)
        c<<aux->dato;

    cout<<endl;

    return c;
}
