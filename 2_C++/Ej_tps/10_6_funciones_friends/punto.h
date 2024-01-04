#ifndef PUNTO_H
#define PUNTO_H


class Punto
{
    private:
            double mx;
            double my;

            void assignX(double);
            void assignY(double);

    public:

        Punto(double a =0, double b=0);  //Constructor parametrizado y por defecto
        Punto(const Punto&);    //Constructor de copia

        void setPunto(double, double);
        void SetPunto(const Punto &);
        inline void SetX(double a) {assignX(a);};
        inline void SetY(double b) {assignY(b);};

        inline Punto & getPunto()  { return(*this); }
        inline double getX() const { return mx; }   //Se usa el const atras de la funcion cuando el objeto invocante de la funcion no es modificado
        inline double getY() const { return my; }

        Punto& operator = (const Punto &); //Este operador sobrecargado debe ser miembro de la funcion al igual que los operadores unarios

        friend Punto operator +(const Punto&,const Punto&);
        friend Punto operator -(const Punto&,const Punto&);

        /* El objetivo es el uso del operador friend, de manera de recibir los dos parámetros en forma
         * explícita y poder realizar la suma int + Punto. El objeto int es elevado a Punto,
         * debido a que existe el constructor que lo soporta.
         */
};

Punto operator +(const Punto&,const Punto&);
Punto operator -(const Punto&, const Punto&);

#endif // PUNTO_H
