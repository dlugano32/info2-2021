#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>
#include <cmath>
using namespace std;

class Punto
{
    private:
            double mx;
            double my;

            void assignX(double);   //metodos privados para asignar valores a X o Y. Solo los usan los metodos miembro
            void assignY(double);
            static int cont_creado;
            static int cont_exist;

    public:

        Punto(double a =0, double b=0);  //Constructor parametrizado y por defecto
        Punto(const Punto&);    //Constructor de copia
        ~Punto();

        void setPunto(double, double);
        void setPunto(const Punto &);
        inline void SetX(double a) {assignX(a);};
        inline void SetY(double b) {assignY(b);};

        inline Punto& getPunto()  { return(*this); }
        inline double getX() const { return mx; }
        inline double getY() const { return my; }

        inline static int getCantCreada() { return cont_creado; };
        inline static int getCantExistente() { return cont_exist; };


        double modulo() const;

        /* Se usa el const atras de la funcion cuando el objeto invocante de la funcion no es modificado.
         * Esto me permite, dentro de una funcion miembro con los objeto de entrada constante, llamar a otra funcion miembro
         * de manera de asegurarle a la funcion (porque no sabria de otra forma) que el objeto pasado por parametro a esta ultima
         * no va a ser modificado
         * */

        //Sobrecarga de operadores
        Punto& operator = (const Punto &);      //Este operador sobrecargado debe ser miembro de la funcion al igual que los operadores unarios

        friend Punto operator +(const Punto&, const Punto&);
        friend Punto operator -(const Punto&, const Punto&);
        friend bool operator ==(const Punto&, const Punto&);
        friend bool operator !=(const Punto&, const Punto&);
        friend bool operator >(const Punto&, const Punto&);
        friend bool operator <(const Punto&, const Punto&);
        friend ostream & operator <<(ostream &, const Punto&);
        friend istream & operator >>(istream &, Punto&);

        /*
         * El resto de los operadores no deben ser miembros ya que el objetivo es el uso del operador friend, de manera de
         * recibir los dos parámetros en forma explícita y poder realizar la suma int + Punto. El objeto int es elevado a Punto,
         * debido a que existe el constructor que lo soporta.
         */
};

//Las funciones friend tiene que ser declaradas fuera de la clase
Punto operator +(const Punto&,const Punto&);
Punto operator -(const Punto&, const Punto&);
bool operator ==(const Punto&, const Punto&);
bool operator !=(const Punto&, const Punto&);
bool operator >(const Punto&, const Punto&);
bool operator <(const Punto&, const Punto&);

//Recibo por parametro un objeto de la clase iostream
ostream & operator <<(ostream &, const Punto&); //Tengo que devolver la referencia del cout para que pueda seguir imprimiendo en cadena
istream & operator >>(istream &, Punto&);

#endif // PUNTO_H
