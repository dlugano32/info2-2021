#ifndef POLIGONO_H
#define POLIGONO_H

#include "punto.h"

class Poligono
{
    private:
            static int m_cantidadDePoligonos;
            Punto *m_vertices;
            int cant;   //Tamaño de mi vector
            int m_verticesIncorporados; //Puntos incorporados
    public:
            Poligono(int numeroDeLados=3);
            ~Poligono();
            const Punto & getVertice (int numeroDeVertice) const;
            Poligono& operator <<(const Punto &);
            Poligono& operator =(const Poligono &);
            Poligono& operator -= (const Punto &);

            friend ostream & operator << (ostream &c, const Poligono &P);
};

ostream & operator << (ostream &c, const Poligono &P);

#endif // POLIGONO_H
