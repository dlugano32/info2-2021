#include "cargamento.h"

int main()
{
    Cargamento C1("Sputnik","Argentina"), C2("Sputnik","Moldavia"), C3;
    Lote L1(10), L2(5);
    Vacuna V1(-10,1,16, Vacuna::ERROR);

    for(int i=0; i<10; i++)
        ((L1.getVacs())+i)->setVacuna(-10,0,12,Vacuna::OK);

    for(int i=0; i<5; i++)
        ((L2.getVacs())+i)->setVacuna(13,4,0,Vacuna::OK);


    C1<<L1<<L2;
    C2<<L2;
    C3<<L1;
    C3<<V1;

    cout<<C1<<endl;
    cout<<C2<<endl;
    cout<<C3;
}
