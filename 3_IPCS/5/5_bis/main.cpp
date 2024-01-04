#include <iostream>
#include "shmem.h"
#define MAX 256
#define CANT 2
using namespace std;

int main()
{
    int recepcion=0;
    string p=".";
    char receive[MAX];
    char choice;

    struct sensores v[CANT];

    v[0].nro_sensor=0;
    v[0].medicion=57;
    v[1].nro_sensor=1;
    v[1].medicion=89;

    ShMem Q( (char *)p.data(), 'a', MAX);

    if(Q.GetID()!=-1)
    {
        cout<<"Conectado a la Shared memory ID: "<<Q.GetID()<<endl;
    }
    else
    {
        cout<<"No se pudo conectar"<<endl;
        return 0;
    }

    do
    {
        cout<<"Ingrese 1)Mandar mensaje 2)Recibir mensaje 3)Salir"<<endl;
        cin>>choice;

        if(choice=='1')
        {
            cout<<"Ingrese la cantidad de estructuras que desea enviar"<<endl;
            cout<<CANT<<endl;

            if( ( Q.escribir( (void *)&v, CANT )) == true)
                cout<<"Mensaje enviado"<<endl;
            else
                cout<<"No se pudo enviar el mensaje"<<endl;

        }
        else if(choice=='2')
        {
            recepcion=Q.leer( (void *)receive, MAX);

            if( recepcion > 0)
            {
                cout<<"Mensaje de "<<recepcion<<" bytes recibido: "<<endl;

                for(int i=0; i<MAX; i++)
                {
                    printf("%X", receive[i]);
                }
                printf("\n");
            }
            else
                cout<<"No se recibio ningun mensaje"<<endl;
        }

    }while(choice!='3');

    cout<<"Desea borrar el IPC? S/N"<<endl;
    cin>>choice;

    if(choice=='S' || choice=='s')
        Q.SetBorrar(true);
    else
        Q.SetBorrar(false);

    return 0;
}
