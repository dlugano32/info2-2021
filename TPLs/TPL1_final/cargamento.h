#ifndef CARGAMENTO_H
#define CARGAMENTO_H

#include "lote.h"

class Cargamento: public Lote
{
private:
    string fabricante;
    string destino;
public:
    Cargamento ();
    Cargamento (string f, string d);

    Cargamento& operator << (const Lote&);
    Cargamento& operator << (const Vacuna&);

    friend ostream& operator << (ostream &, const Cargamento&);
};
ostream& operator << (ostream &, const Cargamento&);
#endif // CARGAMENTO_H
