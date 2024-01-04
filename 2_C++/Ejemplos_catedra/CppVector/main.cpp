#include "vector.h"
#include <iostream>

using namespace std;

int main( void )
{
    vector vec1(3),vec2,vec3(vec1);

    vec2<<4<<5<<6;

    vec3 = vec1 + vec2;

    vec1[0] = 14;
    vec1[1] = 10;

    cout << "Imprimo los 3 vectores: "<<endl;
    cout << "vec1: " << vec1 << endl;
    cout << "vec2: " << vec2 << endl;
    cout << "vec3: " << vec3 << endl;
}
