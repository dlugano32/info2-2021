#include "preparacion.h"
#include <iostream>
using namespace std;

int main()
{
    Color A;
    Color B(10, 10, 15, "GRIS", 65.0);

    cout << "Color A " << A << endl;
    cout << "Color B " << B << endl;

    cin >> A;
    cout << "Color A " << A << endl;

    A.set_name("ROSADO");
    cout << "El nombre del Color A es ahora: " << A.get_name()<< endl;

    A.set_costo(99.9);
    cout << "El costo del Color A es ahora: " << A.get_costo() << endl;

    A.set_color(23,51,19);
    cout << "La composición de colores del Color A es ahora:\n"
         << "Rojo: " << A.get_Color(RED) << endl
         << "Verde: " << A.get_Color(GREEN) << endl
         << "Azul: " << A.get_Color(BLUE) << endl << endl;

    cout << "Ahora el Color A tiene las siguientes características:" << endl;
    cout << A;

    Color C = A;
    cout << "\nAhora creo el Color C y le asigno las características del Color A:" << endl;
    cout << A;

    Color D;
    cout << "\nAhora creo un nuevo Color D a partir de mezclar el A y el B:" << endl;
    D.crear_color(A, B);
    cout << D;

    Preparacion P1;
    cout << P1;

    Preparacion P2;
    cin >> P2;
    cout << P2;

    cout<<"---------------";
    Preparacion P3 (D, 10);
    cout << P3;

    Preparacion P4 (12, 28, 69, "ESMERALDA", 56.78, 20);
    cout << P4;

    P4.set_costo(P4.get_costo() * 0.8);
    cout << "\n¡Cyber Monday!! - REBAJA del 20% en el costo por litro!!!" << P4;

    cout << "\n¡Cyber Monday!! - ¡Aprovecho la oferta! Compro 1 litro mas.." << ++P4 ;

    cout << "\n¡Cyber Monday!! - ¡Quiero mas! Compro 9 litros mas.." << (P4+9) ;

    Preparacion P5;
    P5 = P3;
    cout << P5;
}
