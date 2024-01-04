#include "punto.h"

//Contructores
Punto::Punto(double a, double b)
{
    assignX(a);
    assignY(b);
}

Punto::Punto(const Punto &P)
{
    assignX(P.mx);
    assignY(P.my);
}

//Metodos

void Punto::setPunto(double a, double b)
{
    assignX(a);
    assignY(b);
}


void Punto::SetPunto(const Punto &P)
{
    assignX(P.mx);
    assignY(P.my);
}


void Punto::assignX(double a)
{
    if (a>1000)
    {
        mx =1000;
    }
    else if(a < -1000)
    {
        mx=-1000;
    }
    else
    {
        mx=a;
    }

}

void Punto:: assignY(double b)
{
    if (b>1000)
    {
        my =1000;
    }
    else if(b < -1000)
    {
        my=-1000;
    }
    else
    {
        my=b;
    }
}

//Sobrecarga de operadores
Punto& Punto:: operator = (const Punto &P)
{
    mx=P.mx;
    my=P.my;

    return *(this);
}

Punto Punto:: operator + (const Punto & P) const
{
    Punto aux;

    aux.assignX(mx + P.mx);
    aux.assignY(my + P.my);

    return aux;
}

Punto Punto::operator - (const Punto & P) const
{
    Punto aux;

    aux.assignX(mx - P.mx);
    aux.assignY(my - P.my);

    return aux;
}


