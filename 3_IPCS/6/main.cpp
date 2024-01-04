#include <iostream>
#include "shsem.h"
#define MAX 20
using namespace std;


int main()
{
    int recepcion=0;
    string p=".",mensaje;
    char receive[MAX];
    char choice;

    ShSem Q( (char *)p.data(), 'a', MAX);

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
            cout<<"Ingrese el mensaje que desea enviar"<<endl;
            cin>>mensaje;

            if( ( Q.escribir( (void *)mensaje.data(), mensaje.size(), 0) ) == true)
                cout<<"Mensaje enviado"<<endl;
            else
                cout<<"No se pudo enviar el mensaje"<<endl;

        }
        else if(choice=='2')
        {
            recepcion=Q.leer( (void *)receive, MAX, 0);

            if( recepcion > 0)
            {
                cout<<"Mensaje de "<<recepcion<<" bytes recibido: "<<endl<<"-"<<receive<<endl;
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
