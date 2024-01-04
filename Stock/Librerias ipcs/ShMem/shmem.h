#ifndef SHMEM_H
#define SHMEM_H

#include "ipcs.h"

class ShMem : public Ipcs
{
    private:
            char* buffer;
            int size;

            static int indc;

    public:
            ShMem(char * p = NULL , char a = 0 , int tam = 0, bool destroy=false);
            ShMem( const ShMem&);

            bool conectar( char *p, char a);
            bool escribir ( void * msg, int tam, int inicio) const;
            int leer ( void * msg, int tam, int inicio) const;
            void reset() { indc=0; };

            ~ShMem();

};

#endif // SHMEM_H
