#include <iostream>
#include "lista.h"
#include "persona.h"
using namespace std;

int main()
{
    Lista L1;
    Lista L2;

    Persona P1("Damian", "Lugano", 42598202), P2("Ana", "Nunez", 42598206), P3("Juan","Cata",43678045), P4("Federico", "Albero", 42598644);

    L1.AgregarElemento(P1, 0);
    L1.AgregarElemento(P2, 1);

    cout<<L1;

    L1.AgregarElemento(P3,0);
    L1.AgregarElemento(P4, 1);

    cout<<L1;

    return 0;
}
