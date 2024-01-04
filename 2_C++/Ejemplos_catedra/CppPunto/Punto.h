#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>

using namespace std;

class Punto
{
    double x, y;

public:
    //Constructores
    Punto(double x = 0, double y = 0);
    Punto(const Punto &c);

    //Metodo de acceso
    void setX(double x);
    double getX() const;
    void setY(double y);
    double getY() const;

    //Sobrecarga de operadores
    Punto operator+(const Punto &c);
    Punto operator-(const Punto &c);
    Punto& operator+=(const Punto &c);
    Punto& operator-=(const Punto &c);
    bool operator ==(const Punto &c);
    bool operator !=(const Punto &c);

    //Sobrecarga globales de operadores
    friend ostream& operator<<(ostream &o, const Punto &c);
    friend Punto operator+(double d, const Punto &c);
};

ostream& operator<<(ostream &o, const Punto &c);
Punto operator+(double d, const Punto &c);

#endif // Punto_H
