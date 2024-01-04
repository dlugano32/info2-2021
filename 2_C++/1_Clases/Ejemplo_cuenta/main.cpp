#include <iostream>
#include "cuenta.h"

using namespace std;

int main()
{
    int monto=0;

    Cuenta P1(1000), P2(P1);     //Aca lo que hago es instanciar los dos objetos, a P1 le cargo 100 y despues copio el saldo de P1 en P2

    cout<<"Saldo P1="<<P1.getSaldo()<<endl<<"Saldo P2="<<P2.getSaldo()<<endl;
    cout<<endl<<"Ingrese monto a transferir de P1 a P2"<<endl;
    cin>>monto;
    P1.transferencia(monto, P2);

    cout<<endl<<"Saldo P1="<<P1.getSaldo()<<endl<<"Saldo P2="<<P2.getSaldo()<<endl;







    return 0;
}
