#include "cuenta.h"

Cuenta::Cuenta()
{
    saldo=0;

}

Cuenta::Cuenta(int valor)
{
    saldo=valor;
}

Cuenta::Cuenta(const Cuenta& copy)
{
    saldo=copy.saldo;
}

void Cuenta::setSaldo(int valor)
{
    saldo+=valor;
}

int Cuenta::getSaldo(void)
{
    return saldo;
}

void Cuenta::transferencia(int monto, Cuenta& P)
{
    saldo-=monto;   //Le quito el monto
    P.setSaldo(monto); //Le sumo el monto a P
}
