#include "vector.h"

vector::vector()
{
    inicio = nullptr;
    size = 0;
    error = -1;
}

vector::vector( int tam )
{
    size = tam;
    inicio = new int[tam];
    error = -1;

    for ( int i = 0 ; i < tam ; i++)
        inicio[i] = 0;

}

vector::vector( const vector & vec )
{
    size = vec.size;
    error = -1;

    inicio = new int[size];

    for ( int i = 0 ; i < size ; i++)
        inicio[i] = vec.inicio[i];

}

int vector::getSize ( void ) const
{
    return size;
}

vector & vector::operator= ( const vector & vec)
{

    delete[] inicio;

    size = vec.size;

    inicio = new int[size];

    for ( int i = 0 ; i < size ; i++)
        inicio[i] = vec.inicio[i];

    return *this;

}

int & vector::operator[] ( int pos )
{        
    if ( pos < size )
        return inicio[pos];

    return error;
}

vector & vector::operator << ( int valor )
{
    int * auxiliar = new int[size+1];

    size++;

    for ( int i = 0 ; i < (size-1) ; i++ )
        auxiliar[i] = inicio[i];

    if ( inicio!= nullptr )
        delete[] inicio;

    auxiliar[size-1] = valor;

    inicio = auxiliar;

    return *this;
}

ostream & operator <<(ostream & o, vector & v)
{
    o << "[";

    for (int i = 0 ; i < (v.getSize() - 1) ; i++ )
        o << v[i] << ",";

    o<<v[ v.getSize() - 1 ]<<"]";

    return o;
}

vector vector::operator + ( const vector & vec2 ) const
{
    vector auxiliar (size + vec2.size);

    for (int i = 0 ; i < size ; i++ )
        auxiliar[i] = inicio[i];

    for ( int i = 0 ; i < vec2.size ; i++)
        auxiliar[i+size] = vec2.inicio[i];

    return auxiliar;
}


vector::~vector()
{
    if ( inicio != nullptr )
        delete[] inicio;
}
