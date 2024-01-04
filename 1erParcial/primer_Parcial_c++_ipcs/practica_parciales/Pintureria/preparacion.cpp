#include "preparacion.h"

int Preparacion::cant=0;

Preparacion::Preparacion() :Color()
{
    litros=0;
    costo_t=0;
    cant++;
}

Preparacion::Preparacion(const Color &c, int lit): Color(c)
{
    litros=lit;
    costo_t= litros*(Color::get_costo());
    cant++;
}

Preparacion::Preparacion(int r, int g, int b, string nombre, float costo, int lit): Color(r,g,b, nombre, costo)
{
    litros=lit;
    costo_t= litros*get_costo();
    cant ++;
}

Preparacion::~Preparacion()
{

}

void Preparacion::set_costo(float valor)
{
    costo_t=litros * valor;

    Color::set_costo(valor);
}

float Preparacion::get_litros()
{
    return litros;
}

Preparacion &Preparacion::operator=(Preparacion &P)
{
    Color::operator=((Color &) P);

    litros=P.litros;
    costo_t=P.costo_t;

    return *this;
}

Preparacion& Preparacion::operator ++()
{
    litros++;
    costo_t= litros*Color::get_costo();

    return *this;
}

Preparacion& Preparacion::operator +(int lit)
{
    litros+=lit;
    costo_t= litros*Color::get_costo();
    return *this;
}

istream & operator >> (istream & in, Preparacion & P)
{
    in>>(Color &) P;
    cout<<"Litros: ";
    in>>P.litros;
    P.set_costo(P.Color::get_costo());  //Directamente calculo el valor total

    return in;
}

ostream & operator <<(ostream & out, Preparacion & P)
{
    out<<(Color &) P;
    out<<"Litros: "<<P.litros<<endl;
    out<<"Costo total = "<<P.costo_t<<endl;

    return out;
}
