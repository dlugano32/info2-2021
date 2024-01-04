#include <iostream>
#include <math.h>
#include "complejo.h"

using namespace std;



int main()
{
    Complejo N1;
    float Real=0, Imag=0;
    cout<<"Ingrese un numero complejo C=(Real; Imaginario)"<<endl;
    cin>>Real;
    cin>>Imag;

    N1.set_Real( Real);
    N1.set_Imag( Imag);

    cout<<"Usted ingreso : C=("<<N1.get_real()<<";"<<N1.get_imag()<<")\n";


    return 0;
}
