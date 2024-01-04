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

Punto operator +(const Punto& P1,const Punto& P2)
{
    Punto aux;

    aux.assignX( P1.getX() +P2.getX() );
    aux.assignY( P1.getY() +P2.getY() );

    return aux;
}

Punto operator -(const Punto& P1, const Punto& P2)
{
    Punto aux;

    aux.assignX( P1.getX() -P2.getX() );
    aux.assignY( P1.getY() -P2.getY() );

    return aux;
}


