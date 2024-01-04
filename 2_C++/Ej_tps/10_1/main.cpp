#include <iostream>
#include "punto.h"

using std::cout;
using std::endl;

#define PRESS_KEY std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();

int main(void)
{
    Punto p(3000.12,4.45);
    Punto r;
    // Punto q(5.7); -- Error de sintaxis
    cout <<"1. punto p: ("<<p.getX()<<";"<<p.getY()<<")"<<endl;
    cout <<"2. punto r: ("<<r.getX()<<";"<<r.getY()<<")"<<endl;
    r.SetX(-2000.22);
    r.SetY(3.33);
    cout <<"3. punto r: ("<<r.getX()<<";"<<r.getY()<<")"<<endl;
    p.setPunto(9900.9,8800.8);
    cout <<"4. punto p: ("<<p.getX()<<";"<<p.getY()<<")"<<endl;
    r=p.getPunto();
    cout <<"5. punto r: ("<<r.getX()<<";"<<r.getY()<<")"<<endl;
    PRESS_KEY;
}
