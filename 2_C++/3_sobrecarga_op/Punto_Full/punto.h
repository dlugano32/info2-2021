#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>
using namespace std;

class Punto
{
    private:
            double mx;
            double my;

    public:
            //Constructores

            Punto(double x =0, double y=0);   //Constructor por defecto y parametrizado
            Punto(const Punto &);               //Constructor de copia

            //Metodos de acceso
            void setPunto(double, double);
            void setPunto(const Punto &);
            inline void setX(double a) { mx=a; };
            inline void setY(double b) { my=b; };

            inline Punto& getPunto()  { return(*this); }
            inline double getX() const { return mx; }
            inline double getY() const { return my; }

            /* Se usa el const atras de la funcion cuando el objeto invocante de la funcion no es modificado.
             * Esto me permite, dentro de una funcion miembro con los objeto de entrada constante, llamar a otra funcion miembro
             * de manera de asegurarle a la funcion (porque no sabria de otra forma) que el objeto pasado por parametro a esta ultima
             * no va a ser modificado
             * */

            //Sobrecarga de operadores

            Punto operator+ (const Punto &) const;
            Punto operator- (const Punto &) const;
            Punto& operator+= (const Punto &);
            Punto& operator-= (const Punto &);
            Punto operator ++(int);    //post-incremento a++;
            Punto& operator ++();       //preincremento ++a;
            bool operator == (const Punto&);
            bool operator != (const Punto&);

            //sobrecarga de operadores globales
            friend ostream& operator <<( ostream &, const Punto &);
            friend Punto operator + (double, const Punto&);

};

ostream& operator <<( ostream &, const Punto &);
Punto operator + (double, const Punto&);


#endif // PUNTO_H
