#ifndef IPCS_H
#define IPCS_H

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include "cstdio"
#include "cerrno"

class Ipcs
{
    protected:
                key_t llave;    //Sirve para conectarse al ipc
                bool borrar;    //Me indica si borrar el ipc al final del proceso
    public:
        Ipcs();

        key_t GetKey(void) const;
        void SetBorrar (bool );

};

#endif // IPCS_H
