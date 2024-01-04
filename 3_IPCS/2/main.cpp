#include <iostream>
#include "msgqueue.h"

using namespace std;


int main()
{
    int recepcion=0;
    string p=".", mensaje;
    char receive[MAX];
    char choice;

    MsgQueue Q((char *) p.data(), 'a', false);

    if(Q.GetID()!=-1)
    {
        cout<<"Conectado a la message queue ID: "<<Q.GetID()<<endl;
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

            if( Q.enviarMsj( (char *)mensaje.data(), mensaje.size(), 1) )
                cout<<"Mensaje enviado"<<endl;
            else
                cout<<"No se pudo enviar el mensaje"<<endl;

        }
        else if(choice=='2')
        {
            if( ( recepcion=Q.recibirMsj( receive, MAX, 0) ) !=-1)
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
