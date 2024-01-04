#include <iostream>
#include "lista.h"
#include "persona.h"
using namespace std;

int main()
{
    Lista L1;
    Lista L2;

    Persona P1("Damian", "Lugano", 42598202), P2("Ana", "Nunez", 42598206), P3("Juan","Cata",43678045), P4("Federico", "Albero", 42598644);

    L1.AgregarNodoFinal(P1);
    L1.AgregarNodoFinal(P2);

    L2.AgregarNodoFinal(P3);
    L2.AgregarNodoFinal(P4);

    cout<<"Lista 1 :\n"<<L1<<"Lista 2: \n"<<L2<<endl;

    L1+=L2;

    cout<<"------------------------------------"<<endl;

    cout<<"Lista 1 :\n"<<L1<<"Lista 2: \n"<<L2<<endl;

    return 0;
}
