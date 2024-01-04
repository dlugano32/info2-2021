#include <cmath>
#include "punto.h"

Punto::Punto(const Punto& P)
{
    x=P.x;
    y=P.y;
}

void Punto::setPunto(float a,float b)
{
    x=a;
    y=b;
}

void Punto::setX(float a)
{
    x=a;
}

void Punto::setY(float b)
{
    y=b;
}

float Punto::getX()
{
    return(x);
}
float Punto::getY()
{
    return(y);
}

Punto Punto::getPunto()
{
    Punto P;

    P.x=getX();
    P.y=getY();

    return P;
}


float Punto::getModulo()
{
    return( sqrt( pow( getX(),2 ) + pow(getY(),2 ) ) );
}
