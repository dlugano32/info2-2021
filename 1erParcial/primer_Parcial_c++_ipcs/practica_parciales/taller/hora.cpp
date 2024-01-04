#include "hora.h"

Hora::Hora()
{
    hora=0;
    min=0;
}

Hora::Hora(int h, int m)
{
    hora=h;
    min=m;
}

ostream & operator <<(ostream &c, const Hora& H)
{
    c<<H.hora<<":"<<H.min;
    return c;
}
