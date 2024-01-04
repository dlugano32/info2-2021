#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

class vector
{
private:
    int size;
    int *inicio;
    int error;

public:
    vector();
    vector(int );
    vector(const vector &);

    int getSize ( void ) const;

    vector & operator= ( const vector & );

    int& operator[] ( int );

    vector operator + ( const vector & ) const;

    vector & operator << ( int );

    ~vector();

};

ostream & operator << (ostream &, vector &);

#endif // VECTOR_H
