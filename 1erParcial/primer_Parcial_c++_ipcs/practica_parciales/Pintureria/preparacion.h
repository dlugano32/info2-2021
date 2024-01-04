#ifndef PREPARACION_H
#define PREPARACION_H

#include "color.h"

class Preparacion :public Color
{
    private:
        float costo_t; //Costo total de la preparacion ==> costo_t=litros*costo;
        int litros; // cantidad de litros a preparar
        static int cant; // cantidad de objetos tipo “preparación” creados.

    public:
        Preparacion();
        Preparacion(const Color & c, int lit);
        Preparacion(int r, int g, int b, string nombre, float valor , int lit);
        ~Preparacion();

        void set_costo ( float valor); // Setea el costo por litro , y actualiza el de preparación
        float get_litros ( ); // Retorna los litros de la preparación
        Preparacion& operator= (Preparacion&); // Sobrecarga de operador =

        Preparacion & operator ++(void);
        Preparacion & operator +(int lit);

        // Realizar la sobrecarga de los operadores “++” y “+” de forma que permita incrementar los litros así:
        // ++A; y A + 3 ; //Siendo A un objeto de la clase Preparacion.
        friend istream & operator >> (istream &, Preparacion &);
        /*sobrecarga del operador de extracción de flujo (>>) que se usa con el objeto cin para ingresar por consola todos
        los miembros de la clase Color y los litros de la Preparación. El código debe estar optimizado*/
        friend ostream & operator <<(ostream &, Preparacion &);
};

istream & operator >> (istream &, Preparacion &);
ostream & operator <<(ostream &, Preparacion &);

#endif // PREPARACION_H
