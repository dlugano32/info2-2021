#include "msgqueue.h"

int main(void)
{
    string mensaje="Hola mundo";
    char recibido[15];
    string a=".";
    int recepcion;

    MsgQueue Q( (char*) a.data() , 'a' , false);

    if(Q.GetID()!=MsgQueue::DISCONNECTED)
        cout<<"Conectado a la message queue ID: "<<Q.GetID()<<endl;
    else
    {
        cout<<"No se pudo conectar a la message queue"<<endl;
        return 0;
    }

    if( fork()!=0 ) //Proceso padre
    {
        if( Q.enviarMsj((void*) mensaje.data(), mensaje.size(), 1) )
            cout<<"Padre: Mensaje enviado"<<endl;
        else
            cout<<"Padre: Error-Mensaje no enviado"<<endl;

        Q.SetBorrar(true);

        wait(NULL);
    }
    else
    {
        recepcion=Q.recibirMsj( recibido, 10, 0);
        if(recepcion!=0)
        {
            cout<<"HIJO: "<<recibido<<endl;
            cout<<"HIJO: Bytes recibidos :"<<recepcion<<endl;
        }
        else
        {
            cout<<"HIJO: Error-Mensaje no recibido"<<endl;
        }
    }

    return 0;
}
