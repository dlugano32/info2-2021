#include <iostream>
#include "Punto.h"

using namespace std;

int main()
{
    Punto c1(2, 3), c2(c1), c3;

    c3.setX(4);
    c3.setY(1);
    c3 += c1;

    cout << "C1 = " << c1 << " C2 = " << c2 << " C3 = " << c3 << endl;
    cout << endl;
    cout << "C1 = " << c1 << endl;
    cout << "C1+C2 = " << c1 + c2 << endl;
    cout << "C3 = " << c3 << endl;
    cout << "C1 == C2 ? ";
    if(c1 == c2)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    cout << "5 + C3 = " << 5 + c3 << endl;

    cout << endl;
    cout << "Presione enter para continuar" << endl;
    cin.get();  //equivalente a getchar

    return 0;
}
