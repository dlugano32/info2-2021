#ifndef MSGQUEUE_H
#define MSGQUEUE_H

#include "ipcs.h"
#define MAX 256

class MsgQueue : public Ipcs
{
    private:
            struct mymsgbuf
            {
                long mtype; //Numero de mensaje
                char mtext[MAX];    //Puntero al mensaje
            };

            int id; //El id correspondiente para poder usar la msgqueue

    public:
            MsgQueue(char * p = nullptr , char a = 0 , bool destroy = false);
            MsgQueue(const MsgQueue&);

            //Metodos
            bool conectar( char * ,char );

            int GetID(void) const;

            bool enviarMsj ( char * , int , long typ = 1) const;
            int recibirMsj ( char * , int , long typ = 0) const;

            ~MsgQueue();

};

#endif // MSGQUEUE_H
