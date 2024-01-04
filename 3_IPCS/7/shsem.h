#ifndef SHMEM_H
#define SHMEM_H

#include "ipcs.h"

struct sensores
{
    int nro_sensor;
    float medicion;
};

class ShSem : public Ipcs
{
    private:
            char* buffer;
            int size;
            int id_sem;

            int inicio;
            int cant;

            /*
            struct sembuf
            {
              unsigned short int sem_num;	// semaphore number
              short int sem_op;		// semaphore operation
              short int sem_flg;		// operation flag
            };
            */

            void bloquearShMem() const;
            void LiberarShMem() const;

    public:
            ShSem(char * p = NULL , char a = 0 , int tam = 0, bool destroy = false);
            ShSem( const ShSem&);

            bool conectar( key_t llave);
            bool escribir ( void * v, int cant);
            int leer ( void * msg, int longitud);
            void reset();

            ShSem& operator <<( int );
            ShSem& operator <<( sensores &);

            ShSem& operator >>( int &);
            ShSem& operator >>( sensores &);

            ~ShSem();

};

#endif // SHMEM_H
