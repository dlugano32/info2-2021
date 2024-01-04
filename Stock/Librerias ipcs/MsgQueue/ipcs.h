#ifndef IPCS_H
#define IPCS_H

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include "cstdio"
#include "cerrno"

using namespace std;

class Ipcs
{
    protected:
            key_t llave;    //Sirve para conectarse al ipc
            int id;
            bool borrar;    //Me indica si borrar el ipc al final del proceso
            bool conectado;

            bool generateKey(char *path, char a);

    public:
        Ipcs();
        Ipcs(char *path, char c, bool destroy);
        int GetID(void) const;
        key_t GetKey(void) const;
        void SetBorrar (bool);

};

#endif // IPCS_H
