#include "punto.h"

Punto::Punto(double a, double b)
{
    assignX(a);
    assignY(b);
}

void Punto::setPunto(double a, double b)
{
    assignX(a);
    assignY(b);
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
