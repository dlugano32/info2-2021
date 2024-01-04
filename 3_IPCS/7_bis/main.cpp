#include "shsem.h"

#define N 4

int main(void)
{
    string mensaje="Hola mundo";
    string a="/home/d_lugano/infoII/3_IPCS/7_bis/build-lector-Desktop_Qt_5_12_2_GCC_64bit-Debug";

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

    //Proceso escritor

    struct sensor medicion[N];

    for(int i=0; i<N; i++)
    {
        medicion[i].nro_sensor=i;
        cout<<"PADRE: Medicion sensor N°"<<i<<": ";
        cin>>medicion[i].medicion;
    }

    Q.reset();

    Q<<(int)N;

    for ( int i = 0 ; i < N ; i ++)
    {
        Q<<medicion[i];
    }

    cout<<"PADRE: datos enviados"<<endl;


    return 0;
}
