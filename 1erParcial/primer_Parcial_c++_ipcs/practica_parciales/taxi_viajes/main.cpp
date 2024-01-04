#include <iostream>
#include "viajes.h"

using namespace std;

int main()
{
//    bool aux = true;
    //Creo un objeto Viajes
    Viajes Gutierrez("ABC123", 15245630, "GUTIERREZ FERNANDO", 15, 220);
    Viajes Pocho("NNP123", 32756877, "FERNANDEZ (POCHO) CARLOS", 85, 350);
    Viajes Tato ("SRK850", 45125478, "GARCIA (TATO) FRANCO");


    //Lo imprimo
    cout << "########## LISTADO ACTUALIZADO #################### \n";
    cout << Gutierrez << Pocho << Tato;

    Gutierrez.set_viaje (100,200);

    //Lo imprimo
    cout << "########## LISTADO ACTUALIZADO #################### \n";
    cout << Gutierrez << Pocho << Tato;


//    do{
//        aux = dia1.

//    }
//    while ()

    cout << "\n";

    return 0;
}
