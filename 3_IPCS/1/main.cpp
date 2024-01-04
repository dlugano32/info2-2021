#include <iostream>
#include "msgqueue.h"

using namespace std;

int main()
{
    string mensaje="Hola mundo";
    char recibido[15];
    string a=".";
    int recepcion;

    MsgQueue Q( (char*) a.data() , 'a' , true);

    if(Q.GetID()!=-1)
        cout<<"Conectado a la message queue ID: "<<Q.GetID()<<endl;
    else
    {
        cout<<"No se pudo conectar a la message queue"<<endl;
        return 0;
    }

    if( fork()!=0 ) //Proceso padre
    {
        Q.enviarMsj((char *)mensaje.data() , mensaje.size(), 1);

        cout<<"Padre: Mensaje enviado"<<endl;

        wait(NULL);
    }
    else
    {
        recepcion=Q.recibirMsj( recibido, 15, 0);

        if(recepcion!=0)
        {
            cout<<"HIJO: "<<recibido<<endl;
            cout<<"HIJO: Bytes recibidos :"<<recepcion<<endl;
        }
    }

    return 0;
}
