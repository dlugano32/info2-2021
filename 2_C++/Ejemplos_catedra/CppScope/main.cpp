#include <iostream>

using namespace std;

int a;

int main(void)
{
    int a;
    a=5;
    ::a=10;

    cout << "a local vale " << a;
    cout << endl;
    cout << "a global vale " << ::a;
    cout << endl << endl;

    cout << "Presione enter para continuar\n";
    getchar();

    return 0;
}
