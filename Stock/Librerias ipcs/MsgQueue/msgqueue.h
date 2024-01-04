#ifndef MSGQUEUE_H
#define MSGQUEUE_H

#include "ipcs.h"
#define MAX 256



class MsgQueue : public Ipcs
{
    private:
        struct mymsgbuf
        {
            long mtype; //Tipo de mensaje
            char mtext[MAX];
        };

    public:
            MsgQueue(char * p = nullptr , char a = 0 , bool destroy = false);

            //Metodos
            bool conectar( char * ,char );

            bool enviarMsj ( void * , int) const;
            int recibirMsj ( void * , int , long typ = 0) const;

            ~MsgQueue();

};

#endif // MSGQUEUE_H
