#ifndef SHMEM_H
#define SHMEM_H

#include "ipcs.h"

struct sensores
{
    int nro_sensor;
    float medicion;
};

class ShMem : public Ipcs
{
    private:
            char* buffer;
            int size;

    public:
            ShMem(char * p = NULL , char a = 0 , int tam = 0, bool destroy=false);
            ShMem( const ShMem&);

            bool conectar( key_t llave);
            bool escribir ( void * v, int cant) const;
            int leer ( void * msg, int cant) const;

            ~ShMem();

};

#endif // SHMEM_H
