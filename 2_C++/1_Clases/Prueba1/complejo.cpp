#include "complejo.h"

Complejo::Complejo()
{
    real=0;
    imag=0;
}

void Complejo::set_Real(float r)
{
    real=r;
}

void Complejo::set_Imag(float i)
{
    imag=i;
}

float Complejo::get_real()
{
    return real;
}

float Complejo::get_imag()
{
    return imag;
}

/*
float Complejo::get_Modulo()
{
      float modulo;

      modulo= (float) sqrt(pow(real,2) , pow(imag, 2) ) ;
}
*/
