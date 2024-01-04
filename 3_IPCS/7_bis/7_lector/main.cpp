#include  "shsem.h"
#include <iostream>
using namespace std;


int main (void)
{
    string mensaje="Hola mundo";
    string a="/home/d_lugano/infoII/3_IPCS/7_bis/build-lector-Desktop_Qt_5_12_2_GCC_64bit-Debug";

    int cant_sensores=0;
    sensor *mediciones;


    ShSem Q( (char*) a.data() , 'a' , 256, false);

    if(Q.GetID()!=-1)
    {
        cout<<"Conectado a la shared memory ID: "<<Q.GetID()<<endl;
        cout<<"Con semaforo ID:"<<Q.getSemID()<<endl;
    }
    else
    {
        cout<<"No se pudo conectar a la shared memory"<<endl;
        return 0;
    }

    Q.reset();

    Q>>&cant_sensores;

    mediciones= new sensor [cant_sensores];

    for(int i=0; i<cant_sensores; i++)
    {
        Q>>mediciones[i];
    }

    cout<<"Cantidad de sensores: "<<cant_sensores<<endl;

    for(int i=0; i<cant_sensores; i++)
    {
        cout<<"Medicion sensor N°"<<mediciones[i].nro_sensor<<": "<<mediciones[i].medicion<<endl;
    }

    delete [] mediciones;

    return 0;
}
