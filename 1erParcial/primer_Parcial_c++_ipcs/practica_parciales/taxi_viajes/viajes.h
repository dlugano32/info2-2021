#ifndef VIAJES_H
#define VIAJES_H

#include "taxi.h"
#include "pila.h"

class Viajes : public Taxi
{
    private:
        Pila P;
    public:
        Viajes();
        ~Viajes();
        Viajes(string pat, long lic, string ApeNom, int duracion=0, int precio=0);
        void set_viaje(int duracion, int precio);
        void liquidacion(float* ganancia_agencia, float* ganancia_chofer );

        friend ostream & operator << (ostream &, Viajes &);
};

ostream & operator << (ostream &, Viajes &);

#endif // VIAJES_H
