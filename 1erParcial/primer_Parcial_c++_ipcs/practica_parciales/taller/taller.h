#ifndef TALLER_H
#define TALLER_H

#include <iostream>
#include "hora.h"

using namespace std;

class Taller
{
    protected:
        string Marca;
        string Modelo;
        string Patente;
        Hora h;
    public:
        Taller();//Inicializa a las variables Marca.Modelo y Patente con la leyenda SIN DATOS y la Hora en 0,0

        Taller(const string&, const string& ,const string&,int,int );// inicializa a Marca, Modelo y Patente y la hora de entrada

        // agregar mas métodos si considera que hace falta
        static const string Tarea[4];
        //tareas PREDEFINIDAS que deben ser cargadas ej "C_Bujias","Afinación","Embrague","C_Amortiguadores"
        static const int Costo[4];
        // costo de las tareas indicadas Por ej 2000,5000,8800,3500
        friend ostream& operator<< (ostream&,Taller&);
};

ostream& operator<< (ostream&,Taller&);
#endif // TALLER_H
