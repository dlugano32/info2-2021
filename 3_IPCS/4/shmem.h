#ifndef SHMEM_H
#define SHMEM_H

#include "ipcs.h"

class ShMem : public Ipcs
{
    private:
            char* buffer;
            int size;
            int id;

    public:
            ShMem(char * p = NULL , char a = 0 , int tam = 0, bool destroy = false);
            ShMem( const ShMem&);

            bool conectar( char * ,char , int);
            bool escribir ( void * msg, int longitud, int inicio = 0) const;
            int leer ( char * buf, int longitud, int inicio = 0) const;

            ~ShMem();

};

#endif // SHMEM_H
