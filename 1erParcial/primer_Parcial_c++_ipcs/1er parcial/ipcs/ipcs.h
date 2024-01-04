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
            bool borrar;    //Me indica si borrar el ipc al final del proceso

            bool generateKey(char *path = nullptr, char a=0);

    public:
        Ipcs(char *path=nullptr, char a=0, bool destroy=false);
        Ipcs(key_t key, bool destroy); //Constructor de copia

        key_t GetKey(void) const;
        void SetBorrar (bool);

};

#endif // IPCS_H
