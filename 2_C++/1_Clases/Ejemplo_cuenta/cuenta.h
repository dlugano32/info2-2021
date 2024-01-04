#ifndef CUENTA_H
#define CUENTA_H


class Cuenta
{
    private:
                int saldo;

    public:

    Cuenta();                   //Constructor por defecto
    Cuenta(int);                //Constructor por sobrecarga
    Cuenta(const Cuenta &);     //Constructor copia

    void setSaldo(int);         //Seteo el saldo
    int getSaldo();             //Consigo el valor del saldo
    void transferencia(int, Cuenta&);


};

#endif // CUENTA_H
