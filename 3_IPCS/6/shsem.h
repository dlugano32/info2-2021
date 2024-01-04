#ifndef SHMEM_H
#define SHMEM_H

#include "ipcs.h"

class ShSem : public Ipcs
{
    private:
            char* buffer;
            int size;
            int id_sem;

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
            bool escribir ( void * msg, int longitud, int inicio = 0) const;
            int leer ( void * msg, int longitud, int inicio = 0) const;

            ~ShSem();

};

#endif // SHMEM_H
