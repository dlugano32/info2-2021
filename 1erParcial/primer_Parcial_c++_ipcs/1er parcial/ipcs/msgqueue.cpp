#include "ipcs.h"
#include "msgqueue.h"

MsgQueue::MsgQueue(char *p, char a, bool destroy) : Ipcs(p, a, destroy)
{
    id=-1;
    conectar(p,a);
}

MsgQueue::MsgQueue(const MsgQueue &a) :Ipcs(a.llave, a.borrar)
{
    id=a.id;
}

bool MsgQueue::conectar(char * p, char a)
{
    if(id==DISCONNECTED)
    {
        if(llave==-1)
        {
            if( generateKey(p,a) ==false )
            {
                cout<<"No se pudo crear la llave"<<endl;
                id=DISCONNECTED;
                return false;
            }
        }

        id=msgget(llave, IPC_CREAT | 0666);

        if(id<0)
        {
            perror("\nError msgget");
            id=DISCONNECTED;
            return false;
        }
    }

    return true;
}

int MsgQueue::GetID() const
{
    return id;
}

bool MsgQueue::enviarMsj(void *p, int tam, long typ) const
{
    if(id == DISCONNECTED)
    {
        return false;
        cout<<"Message queue no conectada"<<endl;
    }

    if(tam <=MAX)       //MAX es el size de mi mtext
    {
        mymsgbuf mensaje;

        mensaje.mtype=typ;

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

    if(id == DISCONNECTED)
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


