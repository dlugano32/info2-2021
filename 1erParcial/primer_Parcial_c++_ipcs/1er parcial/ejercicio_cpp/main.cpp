#include <iostream>
using namespace std;

#include "poligono.h"

int main()
{
    Poligono triangulo (3);
    Punto vertice1(0, 10), vertice2(10,15), vertice3(8,7), vertice4(3,6);
    triangulo<<vertice1;
    triangulo<<vertice2;
    triangulo<<vertice3;
    triangulo<<vertice4;

    Poligono figura(4);
    figura=triangulo;

    cout<<triangulo;
    cout<<figura;

    triangulo-= vertice3;
    triangulo-= vertice3;

    cout<<triangulo;
    cout<<figura;



}
