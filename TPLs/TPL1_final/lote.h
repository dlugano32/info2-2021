#ifndef LOTE_H
#define LOTE_H

#include "vacuna.h"

class Lote
{
    protected:
        Vacuna * p;
        unsigned int cant;

    public:
        Lote(unsigned int=0);
        Lote(const Lote &);
        ~Lote();

        unsigned int getCant ()const;
        Vacuna * getVacs() const;
        void setTempBatch(int);
        int getBadVacs();

        Lote & operator << (const Vacuna &);

        Vacuna & operator [] (unsigned int);
};

#endif // LOTE_H
