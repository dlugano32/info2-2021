#include "ipcs.h"
#include "msgqueue.h"

MsgQueue::MsgQueue(char *p, char a, bool destroy) : Ipcs(p, a, destroy)
{
    conectar(p,a);
}

bool MsgQueue::conectar(char * p, char a)
{
    if(llave==-1)
    {
        if( generateKey(p,a) ==false )
        {
            cout<<"No se pudo crear la llave"<<endl;
            return false;
        }
    }

    id=msgget(llave, IPC_CREAT | 0666);

    if(id<0)
    {
        perror("\nErrpr msgget");
        return false;
    }

    conectado=true;

    return true;
}

bool MsgQueue::enviarMsj(void *p, int tam) const
{
    if(!conectado)
    {
        return false;
        cout<<"Message queue no conectada"<<endl;
    }

    if(tam <=MAX)       //MAX es el size de mi mtext
    {
        mymsgbuf mensaje;

        mensaje.mtype=1;

        for(int i=0; i<tam; i++)
        {
            mensaje.mtext[i]=*( (char *)p +i);
        }

        if( msgsnd(id, (mymsgbuf *) &mensaje, tam, IPC_NOWAIT) ==-1 )
        {
            cout<<"Error-al enviar el mensaje"<<endl;
            perror("\nError");
            return false;
        }
    }

    return true;
}

int MsgQueue::recibirMsj(void *p, int tam, long typ) const
{
    int aux=0;

    if(!conectado)
    {
        return false;
        cout<<"Message queue no conectada"<<endl;
    }

    if(tam <=MAX)
    {
        mymsgbuf mensaje;

        aux= msgrcv( id, (mymsgbuf *) &mensaje, tam, typ,  0);

        if(aux>0)
        {
            for(int i=0; i<tam; i++)
                *( (char*) p+i)=mensaje.mtext[i];
        }
        else
        {
            cout<<"Error-Al recibir el mensaje"<<endl;
            return false;
        }

    }

    return aux;
}

MsgQueue::~MsgQueue()
{
    if(borrar)
    {
        msgctl(id, IPC_RMID, nullptr);  //Desconecta el MsgQueue y lo borra
        cout<<"Recursos liberados"<<endl;
    }
}


