#include <iostream>

using namespace std;

void funcion(int i);
void funcion(double d);
void funcion(const char *s);

int main(void)
{
    funcion(123);
    cout << endl;
    funcion(4.5);
    cout << endl;
    funcion("HOLA");
    cout << endl;

    cout << endl;
    cout << "Presione enter para continuar\n";
    getchar();

    return 0;
}

void funcion(int i)
{
    cout << "\n El argumento es un entero";
}

void funcion(double d)
{
    cout << "\n El argumento es un double";
}

void funcion(const char *s)
{
    cout << "\n El argumento es un string";
}

