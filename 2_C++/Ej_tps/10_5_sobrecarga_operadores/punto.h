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

        Punto& operator = (const Punto &);
        Punto operator + (const Punto &) const;
        Punto operator - (const Punto &) const;

        /*Entender que no es necesario sobrecargar la suma Punto + int ya que existe un constructor
         * que puede elevar el objeto int a objeto Punto
         */

};

#endif // PUNTO_H
