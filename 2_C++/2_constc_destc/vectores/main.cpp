#include <iostream>
#include <cmath>
#include "punto.h"

#define N 5

using namespace std;

int main()
{
    Punto P[N];
    float x_=0, y_=0;
    int mayor=0, menor=0;
    int flag_M=0, flag_m=0;

    cout<<"Ingrese "<<N<<" cantidad de vectores"<<endl<<endl;

    for(int i=0; i<N; i++)
    {
        cout<<"Ingrese la componente X e Y del vector "<<i+1<<endl;
        cin>>x_;
        cin>>y_;

        P[i].setPunto(x_,y_);

    }



    for(int i=0; i<N; i++)
    {
        if( P[i].getModulo() > mayor)
        {
            mayor=P[i].getModulo();
            flag_M=i;
        }

    }

    menor=P[0].getModulo();     //es mejor hacer la comparacion con los modulos de otros vectores que con un numero muy grande

    for(int i=1; i<N; i++)
    {
        if( P[i].getModulo() < menor)
        {
            menor=P[i].getModulo();
            flag_m=i;
        }

    }
    cout<<"El vector mas lejos del origen es: ("<<P[flag_M].getX()<<";"<<P[flag_M].getY()<<")"<<endl;
    cout<<"El vector mas cerca del origen es: ("<<P[flag_m].getX()<<";"<<P[flag_m].getY()<<")"<<endl;
}

