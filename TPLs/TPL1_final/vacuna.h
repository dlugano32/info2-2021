#ifndef VACUNA_H
#define VACUNA_H
#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>

class Vacuna
{

private:
    int temperatura;
    int minutos;
    int segundos;
    bool estado;

public:
    Vacuna(int temp=-80, int min=0, int seg=0, bool est=true); //constructor parametrizado
    Vacuna(const Vacuna & vac); //constructor parametrizado

    void checkEstado();
    void checkTime();
    void setTemp(int);
    void setMin(int);
    void setSeg(int);
    void setEst(bool);
    void setVacuna(int,int,int,bool);
    int getTemp() const;
    int getMin() const;
    int getSeg() const;
    bool getEst()const;
    string getVacuna () const;

    //sobrecarga de operadores
    Vacuna & operator =(const Vacuna &);
    void operator +=(int);
    void operator ++(int);
    bool operator <(const Vacuna &);
    bool operator >(const Vacuna &);
    bool operator ==(const Vacuna &);

    static const bool OK = true;
    static const bool ERROR= false;
};

ostream & operator <<(ostream &c, const Vacuna &);
#endif // VACUNA_H
