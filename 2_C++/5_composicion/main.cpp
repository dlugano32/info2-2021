#include <iostream>
#include "persona.h"

using namespace std;

int main()
{
    Persona empleado("aumento", "fernandez", 42598202);
    Persona trabajador(empleado);

    trabajador.set_nombre("alberto");

    cout<<trabajador.get_nombre();
    cout<<trabajador.get_apellido();
    cout<<trabajador.get_dni()<<endl;

}
