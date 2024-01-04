#include <iostream>

using namespace std;

class Ejemplo
{
public:
    Ejemplo(void);
    ~Ejemplo(void);
};

void funcion();

int main(void)
{
    Ejemplo obj;
    cout << "Este el el main()\n";
    cout << "Presione enter para continuar\n";
    getchar();

    funcion();

    cout << "Termino la funcion y volvemos al main()\n";
    cout << "Presione enter para continuar\n";
    getchar();

    cout << "Ahora declaro creo un objeto dinamicamente\n";
    cout << "Presione enter para continuar\n";
    getchar();

    Ejemplo *pobj;
    pobj = new Ejemplo;

    cout << "Y ahora libero la memoria\n";
    cout << "Presione enter para continuar\n";
    getchar();

    delete pobj;

    cout << "Termina el main()\n";
    cout << "Presione enter para continuar\n";
    getchar();

    return 0;
}

void funcion()
{
    Ejemplo obj;
    cout << "Esta es la funcion\n";
    cout << "Presione enter para continuar\n";
    getchar();
}

Ejemplo::Ejemplo()
{
    cout << "\tEste es el constructor\n";
    cout << "\tPresione enter para continuar\n";
    getchar();
}

Ejemplo::~Ejemplo()
{
    cout << "\tEste es el destructor\n";
    cout << "\tPresione enter para continuar\n";
    getchar();
}

