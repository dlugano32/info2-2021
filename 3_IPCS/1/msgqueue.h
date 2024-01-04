#ifndef MSGQUEUE_H
#define MSGQUEUE_H

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include "cstdio"
#include "cerrno"

#define MAX 256

class MsgQueue
{
    private:
            struct mymsgbuf
            {
                long mtype; //Numero de mensaje
                char mtext[MAX];    //Puntero al mensaje
            };

            key_t llave;    //Sirve para conectarse al ipc
            int id; //El id correspondiente para poder usar la msgqueue
            bool borrar;    //Me indica si borrar el ipc al final del proceso

    public:
            MsgQueue(char * p = nullptr , char a = 0 , bool destroy = false);
            MsgQueue(const MsgQueue&);

            //Metodos
            bool conectar( char * ,char );
            key_t GetKey(void) const;
            int GetID(void) const;

            void SetBorrar (bool );

            bool enviarMsj ( char * , int , long typ = 1) const;
            int recibirMsj ( char * , int , long typ = 0) const;

            ~MsgQueue();

};

#endif // MSGQUEUE_H
