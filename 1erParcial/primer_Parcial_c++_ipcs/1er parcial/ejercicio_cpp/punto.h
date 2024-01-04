#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>
using namespace std;

class Punto
{
    private:
            int m_x, m_y;

    public:
        Punto(int x=0, int y=0);
        int getX() const;
        int getY() const;
        void setXY(int x, int y);

        Punto & operator = ( const Punto &);
        bool operator ==(const Punto &);
};

ostream & operator << (ostream &, const Punto &);   //No necesariamente es friend ya que tengo metodos que me permiten acceder a lo que necesito imprimir
#endif // PUNTO_H
