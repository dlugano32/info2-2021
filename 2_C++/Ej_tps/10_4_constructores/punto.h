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

        inline Punto & getPunto() { return(*this); }
        inline double getX() { return mx; }
        inline double getY() { return my; }
        void operator = (const Punto &);


};

#endif // PUNTO_H
