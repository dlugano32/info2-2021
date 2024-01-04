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


void Punto::setPunto(const Punto &P)
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

double Punto:: modulo() const
{
    return( sqrt( mx*mx + my*my)) ;
}


//Sobrecarga de operadores
Punto& Punto:: operator = (const Punto &P)
{
    mx=P.mx;
    my=P.my;

    return *(this);
}

Punto& Punto::operator++(void)
{
    mx++;
    my++;

    return *this;
}

Punto Punto::operator++(int)
{
    Punto aux(*this);

    mx++;
    my++;

    return aux;
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

bool operator ==(const Punto& P1, const Punto&P2)
{
    bool aux=false;

    if (( P1.getX() == P2.getX() ) && ( P1.getY() == P2.getY() ) )
    {
        aux=true;
    }

    return aux;
}

bool operator !=(const Punto&P1, const Punto&P2)
{
    bool aux=false;

    if (( P1.getX() != P2.getX() ) && ( P1.getY() != P2.getY() ) )
    {
        aux=true;
    }

    return aux;
}

bool operator >(const Punto&P1, const Punto&P2)
{
    bool aux=false;

    if( P1.modulo() > P2.modulo() )
    {
        aux=true;
    }

    return aux;
}


bool operator <(const Punto& P1, const Punto& P2)
{
    bool aux=false;

    if( P1.modulo() < P2.modulo() )
    {
        aux=true;
    }

    return aux;
}

ostream & operator <<(ostream & c, const Punto& P)
{
    c<<"("<<P.getX()<<";"<<P.getY()<<")"<<endl;

    return c;   //Tengo que devolver la referencia del cout para que pueda seguir imprimiendo en cadena
}

istream & operator >>(istream &c, Punto& P)
{
    double x=0,y=0;

    cout<<"x:"; c>>x;
    cout<<"y:"; c>>y;

    P.setPunto(x,y);

    return c;

}
