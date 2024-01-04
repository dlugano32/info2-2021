#ifndef PUNTO_H
#define PUNTO_H


class Punto
{
    private:
           float x;
           float y;

    public:
        Punto(float a =0, float b =0):x(a),y(b){};  //Constructor por defecto y parametrizado
        Punto(const Punto&);                        //Constructor de copia

        void setPunto(float,float);
        void setX(float);
        void setY(float);

        Punto getPunto();
        float getX();
        float getY();

        float getModulo();
};

#endif // PUNTO_H
