#include "color.h"

Color::Color(const Color &c)
{
    Color::operator=(c);  //uso el operador sobrecargado
}

Color::~Color()
{

}

void Color::set_name(const string & nombre)
{
    name=nombre;
}

string & Color::get_name()
{
    return name;
}

void Color::set_costo(float valor)
{
    costo=valor;
}

float Color::get_costo()
{
    return costo;
}

void Color::set_color(int r, int g, int b)
{
    R=r; G=g; B=b;
}

int Color::get_Color(int c)
{
    int aux=0;

    switch (c)
    {
        case RED:   aux=R;
                    break;

        case GREEN: aux=G;
                    break;

        case BLUE:  aux=B;
                    break;

        default:    aux=-1;
    }
    return aux;
}

void Color::crear_color(const Color &a, const Color &b)
{
    set_name(a.name+"-"+b.name);
    set_costo(a.costo+b.costo);

    R=(a.R+b.R)/2;
    G=(a.G+b.G)/2;
    B=(a.B+b.B)/2;
}

Color &Color::operator =(const Color & c)
{
    R=c.R;
    G=c.G;
    B=c.B;

    costo=c.costo;
    set_name(c.name);

    return *this;
}

istream & operator >> ( istream & in, Color & c)
{
    cout<<"R: ";
    in>>c.R;
    cout<<"G: ";
    in>>c.G;
    cout<<"B: ";
    in>>c.B;
    cout<<"Nombre: ";
    in>>c.name;
    cout<<"Costo: ";
    in>>c.costo;

    return in;
}

ostream & operator << ( ostream & out, Color &c)
{
    out<<"Color: "<<c.name<<endl;
    out<<"R: "<<c.R<<"\tG: "<<c.G<<"\tB: "<<c.B<<endl;
    out<<"Costo por litro: "<<c.costo<<endl;

    return out;
}
