#ifndef TAXI_H
#define TAXI_H

#include <iostream>
using namespace std;

class Taxi
{
    protected:
        string Patente;
        long Licencia;
        string ApeNomChofer;


    public:
    Taxi();
    Taxi (string Pat, long lic, string ApeNom);
    Taxi(const Taxi& t);
    ~Taxi();

    void set_datos(string Pat, long lic, string ApeNom);
    Taxi &operator = (Taxi& T);
    friend ostream& operator << (ostream&, Taxi&);
};

ostream& operator << (ostream&, Taxi&);
#endif // TAXI_H
