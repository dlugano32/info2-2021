#ifndef SHMEM_H
#define SHMEM_H

#include "ipcs.h"
struct sensor
{
    int nro_sensor;
    float medicion;
};

class ShSem : public Ipcs
{
    protected:
            char* buffer;
            int size;
            int id_sem;

            static int indc;
            static bool first_t;

            void bloquearShMem() const;
            void LiberarShMem() const;

    public:
            ShSem(char * p = NULL , char a = 0 , int tam = 0, bool destroy = false);
            int getSemID() {return id_sem;};

            bool conectar( char *p, char a);
            bool escribir ( void * msg, int longitud, int inicio = 0) const;
            int leer ( void * msg, int longitud, int inicio = 0) const;
            void reset() { indc=0; };


            ShSem & operator <<(const int);
            ShSem & operator <<(const struct sensor &msg);

            ShSem & operator >>(const int *);
            ShSem & operator >>(const struct sensor &msg);

            ~ShSem();
};

#endif // SHMEM_H
