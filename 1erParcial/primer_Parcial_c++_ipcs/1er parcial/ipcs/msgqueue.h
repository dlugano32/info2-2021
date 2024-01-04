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

        int id;

    public:

            static const int DISCONNECTED=-1;

            MsgQueue(char * p = nullptr , char a = 0 , bool destroy = false);
            MsgQueue(const MsgQueue & a);

            //Metodos
            bool conectar( char * ,char );
            int GetID(void) const;
            bool enviarMsj ( void * , int, long typ=1) const;
            int recibirMsj ( void * , int , long typ = 0) const;

            ~MsgQueue();

};

#endif // MSGQUEUE_H
