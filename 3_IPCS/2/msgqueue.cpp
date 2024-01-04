#include "msgqueue.h"

MsgQueue::MsgQueue(char *p, char a, bool destroy) :Ipcs()
{
    id=-1;  //en caso de que no se pueda setear
    borrar=destroy;

    if(p!=nullptr)
    {
        llave=ftok(p , a);

        if(llave<0)
        {
            perror ("\nError ftok\n");
        }
        else
        {
            id=msgget(llave, IPC_CREAT | 0666);

            if(id<0)
                perror("\nErrpr msgget");
        }
    }
}

MsgQueue::MsgQueue(const MsgQueue & Q) :Ipcs()
{
    id=-1;
    borrar=Q.borrar;

    if(Q.id!=-1)    //Si es -1 se que no esta conectado
    {
        llave=Q.llave;
        id=Q.id;    //Tengo el ID para acceder a la queue
    }
}

bool MsgQueue::conectar(char * p, char a)
{
    bool aux=true;

    llave=ftok(p , a);

    if(llave<0)
    {
        perror ("\nError ftok\n");
        aux=false;
    }
    else
    {
        id=msgget(llave, IPC_CREAT | 0666);

        if(id<0)
        {
            perror("\nErrpr msgget");
            aux=false;
        }
    }

    return aux;
}

int MsgQueue::GetID() const
{
    return id;
}

bool MsgQueue::enviarMsj(char * msg, int tam, long typ) const
{
    bool aux=false;
    mymsgbuf mensaje;

    mensaje.mtype=typ;

    for(int i=0; i<tam; i++)
    {
        mensaje.mtext[i]=msg[i];
    }

    mensaje.mtext[tam]='\0';

    if( ( msgsnd(id, (mymsgbuf *) &mensaje, tam+1, IPC_NOWAIT) != -1) )
        aux=true;

    return aux;
}

int MsgQueue::recibirMsj(char *msg, int tam, long typ) const
{
    int aux=0;
    mymsgbuf mensaje;

    aux= msgrcv( id, (mymsgbuf *) &mensaje, tam, typ,  0);

    if(aux>0)
    {
        for(int i=0; i<tam; i++)
            msg[i]=mensaje.mtext[i];
    }

    return aux;
}

MsgQueue::~MsgQueue()
{
    if(borrar)
    {
        msgctl(id, IPC_RMID, nullptr);  //Desconecta el MsgQueue y lo borra
    }
}


