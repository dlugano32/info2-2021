#include <iostream>
#include "reparacion.h"
using namespace std;

int main()
{
    Reparacion M1("citroen","C3","ABX642",8,45,3,4);//marca-modelo-patente-hora
    //indice de la tarea ,cant_rep

    cout<<M1;
    M1.Tarea(3,1); // Se carga la tarea de índice 3, con la cantidad de repuestos 1
    M1.Tarea(2,2); // Se carga la tarea de índice 2, con la cantidad de repuestos 2
    Reparacion M2("Ford","FIESTA","LOY457",9,20,2,2);//datos vehiculo.hora.min,
    //indice de la tarea ,cant_rep

    cout<<M2;
    M2.Tarea(1,1); // Se carga la tarea de índice 1, con la cantidad de repuestos 1

    return 0;
}
