#ifndef COLOR_H
#define COLOR_H

#include <iostream>

using namespace std;

#define RED 0
#define GREEN 1
#define BLUE 2

class Color
{
    protected:

         int R,G,B; // porcentuales por litro de Preparacion
    private:

        string name; // permite acceder al nombre del Color
        float costo; // costo por litro de la combinación

        public:
             Color(int r=33,int g=33,int b=33, string nombre="Blanco", float valor=1000.00 )
                 :R(r), G(g), B(b), name(nombre), costo(valor) {};

             Color(const Color &);

             ~Color();
        // Función miembro inline que al ejecutarse, al ser “abandonado” un objeto de la clase, libere recursos del sistema.

        void set_name (const string &); // Permite asociar un nombre a una combinación
        string & get_name ( void ); // Permite acceder al nombre de una combinación
        void set_costo( float ); // Setea costo por litro de la combinación
        float get_costo ( void); // Retorna el costo
        void set_color(int, int, int);
        int get_Color ( int ); // Retorna el contenido de R, G o B – utilice macros como argumento
        void crear_color(const Color& A,const Color& B);

        Color& operator = ( const Color& ); // Sobrecarga de operador =
        friend istream & operator >> ( istream &, Color &);
        friend ostream & operator << ( ostream &, Color &);

};

istream & operator >> ( istream &, const Color &);
ostream & operator << ( ostream &, Color &);

#endif // COLOR_H
