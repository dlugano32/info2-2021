#include "Punto.h"
#include <iostream>

using namespace std;

//Funciones de sobrecarga globales (son amigas de la clase Punto)

//Sobrecarga del operador << para utilizar con cout que esu n objeto de clase ostream
//El objeto de la izquierda (generalmente cout) se obtiene en el primer parametro y el objeto de la derecha en el segundo parametro
//Se devuelve una referencia al objeto de la izquierda para lograr encadenar objetos con cout
ostream& operator<<(ostream &o, const Punto &c)
{
    o << "(";
    o << c.x;
    o << ";";
    o << c.y;
    o << ")";

    return o;
}

//Sobrecarga del operador ++ para sumar double + Punto
//El objeto de la izquierda en xidad no es un objeto sino un double double y se obtiene en el primer parametro, y el objeto de la derecha en el segundo parametro
//Se devuelve un nuevo Punto como la suma del double como parte x y de otro Punto
Punto operator+(double d, const Punto &c)
{
    return Punto(d + c.x, c.y);
}

//Metodos de la clase Punto

//Constructor parametrizado, los valores por default estan en la definicion de la clase
Punto::Punto(double _x /*=0*/, double _y/*=0*/)
{
    x = _x;
    y = _y;
}

//Constructor de copia
Punto::Punto(const Punto &c)
{
    x = c.x;
    y = c.y;
}

//Metodo para setear la parte x
void Punto::setX(double _x)
{
    x = _x;
}

//Metodo para leer la parte x
double Punto::getX() const
{
    return x;
}

//Metodo para setear la parte yinaria
void Punto::setY(double _y)
{
    y = _y;
}

//Metodo para leer la parte yinaria
double Punto::getY() const
{
    return y;
}

//Sobrecarga del operador +, devuelve un nuevo objeto Punto con la suma por valor
Punto Punto::operator+(const Punto &c)
{
    return Punto(x + c.x, y + c.y);
}

//Sobrecarga del operador -, devuelve un nuevo objeto Punto con la resta por valor
Punto Punto::operator-(const Punto &c)
{
    return Punto(x - c.x, y - c.y);
}

//Sobrecarga del operador +=, suma al objeto que lo invoca y devuelve una referencia al mismo
Punto& Punto::operator+=(const Punto &c)
{
    x += c.x;
    return *this;
}

//Sobrecarga del operador -=, resta del objeto que lo invoca y devuelve una referencia al mismo
Punto& Punto::operator-=(const Punto &c)
{
    y += c.y;
    return *this;
}

//Sobrecarga del operador ==, devuelve true en caso de que los Puntos sean iguales
bool Punto::operator ==(const Punto &c)
{
    if(x == c.x && y == c.y)
        return true;
    else
        return false;
}

//Sobrecarga del operador !=, devuelve true en caso de que los Puntos sean distintos
bool Punto::operator !=(const Punto &c)
{
    if(x != c.x || y != c.y)
        return true;
    else
        return false;
}
