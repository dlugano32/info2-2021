#include "punto.h"

//Constructores

Punto::Punto(double a, double b)
{
    mx=a;
    my=b;
}

Punto::Punto(const Punto& P)
{
    mx=P.mx;
    my=P.my;
}

//Metodos de acceso

void Punto::setPunto(double a, double b)
{
    mx=a;
    my=b;
}

void Punto::setPunto(const Punto& P)
{
    mx=P.mx;
    my=P.my;
}

//Sobrecarga de operadores

Punto Punto::operator+(const Punto& P) const
{
    Punto aux;

    aux.mx=mx+P.mx;
    aux.my=my+P.my;

    return aux;
}

Punto Punto::operator-(const Punto& P) const
{
    Punto aux;

    aux.mx=mx-P.mx;
    aux.my=my-P.my;

    return aux;
}

Punto& Punto::operator+=(const Punto&P)
{
    mx=mx+P.mx;
    my=my+P.my;

    return (*this);
}

Punto& Punto::operator-=(const Punto&P)
{
    mx=mx-P.mx;
    my=my-P.my;

    return (*this);
}

bool Punto::operator==(const Punto &P)
{
    bool aux=false;

    if( (mx==P.mx) && (my==P.my) )
    {
        aux=true;
    }

    return aux;
}

bool Punto::operator!=(const Punto &P)
{
    bool aux=false;

    if( (mx!=P.mx) && (my!=P.my) )
    {
        aux=true;
    }

    return aux;
}

Punto Punto::operator ++(int)    //post-incremento a++;
{
    Punto aux(*this);


    mx++; my++;

    return aux;
}

Punto& Punto::operator ++()       //preincremento ++a;
{
    mx++; my++;

    return(*this);
}

ostream& operator << (ostream &c, const Punto &P)
{
    c<<"("<<P.getX()<<";"<<P.getY()<<")";
    return c;
}

Punto operator + (double k, const Punto &P)
{
    Punto aux;

    aux.setPunto(k+P.mx , P.my);

    return aux;

}
