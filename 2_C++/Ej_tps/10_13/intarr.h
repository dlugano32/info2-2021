#ifndef INTARR_H
#define INTARR_H

#include <iostream>



class IntArr
{
    private:
            int *p; //puntero del array dinamico
            int size;   //cantidad de elementos del array
            int used;   //cantidad de elementos usados del array p. used será siempre <= a size.

    public:

        //Constructores
        IntArr(int sz); //crea un elemento IntArr con sz elementos disponibles.
        IntArr(int sz, int qtty, int *vec); //crea un elemento IntArr con sz elementos disponibles, y copia qtty elementos del array vec al array p.
        ~IntArr();  //destructor

        //Metodos

        void prtArr (void) const;   //Imprimo el array
        void prtArr (int) const;
        inline int getSize(void) const { return size; };
        inline int getUsed(void) const { return used; };
        double getAvg(void);

};

#endif // INTARR_H
