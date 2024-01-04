#include <iostream>
#include "shsem.h"

#define MAX 256
#define N 2

using namespace std;


void cargar_valores(struct sensores *medicion, int cant);

int main()
{
    string p=".",mensaje;
    ShSem Q( (char *)p.data(), 'a', MAX);

    sensores medicion[N];

    cargar_valores(medicion, N);

    Q.reset();

    //Falta terminar el main y repasar las funciones

    for(int i=0; )

    return 0;
}

void cargar_valores(struct sensores *medicion, int cant)
{

    for(int i=0; i<cant; i++)
    {
        medicion[i].nro_sensor=i;
        cout<<"Valor del sensor "<<i<<" : ";
        cin>>medicion[i].medicion;
    }
}
