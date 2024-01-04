#include "punto.h"

Punto::Punto(int x, int y)
{
    setXY(x,y);
}

int Punto::getX() const
{
    return m_x;
}

int Punto::getY() const
{
    return m_y;
}

void Punto::setXY(int x, int y)
{
    m_x=x;
    m_y=y;
}

Punto & Punto::operator = ( const Punto & P)
{
    setXY(P.m_x, P.m_y);
    return (*this);
}

bool Punto::operator ==(const Punto &P)
{
    bool ret=false;

    if( (m_x==P.m_x) && (m_y==P.m_y))
        ret=true;

    return ret;
}

ostream & operator << (ostream &c, const Punto &P)
{
       c<<"("<<P.getX()<<";"<<P.getY()<<")";

       return c;
}
