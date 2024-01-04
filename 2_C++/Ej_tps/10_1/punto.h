#ifndef PUNTO_H
#define PUNTO_H


class Punto
{
    private:
            double mx;
            double my;

    public:

    Punto ();
    Punto(double a, double b): mx(a), my(b){}; //Constructor por defecto y parametrizado

    void setPunto(double, double);
    inline Punto getPunto() { Punto P;  P.mx=mx; P.my=my;   return P;}
    inline void SetX(double a) { mx=a; }
    inline void SetY(double b) { my=b; }
    inline double getX() { return mx; }
    inline double getY() { return my; }

};

#endif // PUNTO_H
