#include <cstdlib>
#include <iostream>

#include "intarr.h"

using namespace std;

IntArr::IntArr(int sz)
{
    size=sz;
    p=new int[size];
    used=0;

    for(int i=0; i<size; i++)   //lo inicializo en 0
    {
        p[i]=0;
    }

}

IntArr::IntArr(int sz, int qtty, int *vec)
{
    if(qtty>sz)
    {
        sz=qtty;
    }

    size=sz;
    used=qtty;

    p=new int [size];

    for(int i=0; i<used ; i++)
    {
        p[i]=vec[i];
    }
}

IntArr::~IntArr()  //destructor
{
    delete[]p;
    size=0;
}

//Metodos

void IntArr::prtArr (void) const
{
    int i=0;

    cout<<"Array:";

    if(used!=0)
    {
        for( i=0; i<used-1 ; i++)
        {
            cout<<*(p+i)<<";";
        }
        cout<<*(p+used-1)<<endl;
    }
    else
    {
        cout<<"Vacio!!!"<<endl;
    }
}

void IntArr::prtArr (int limit ) const
{
    int i=0;

    cout<<"Array:";

    if(used!=0)
    {
        for( i=0; i<limit-1 ; i++)
        {
            cout<<*(p+i)<<";";
        }
        cout<<*(p+limit-1)<<endl;
    }
    else
    {
        cout<<"Vacio!!!"<<endl;
    }
}

double IntArr::getAvg(void)
{
    double prom=0;

    for(int i=0; i<used; i++)
    {
        prom+=p[i];
    }

    prom=prom/used;

    return prom;
}


void IntArr::addElement (int pos, int val)
{
    addElement(pos, 1, &val);
}

void IntArr::addElement (int pos, int qtty, int *vec)
{
    int *p_aux=nullptr;
    int aux=used;

    if(pos < 0)
    {
        pos=0;
    }
    else if (pos > used)
    {
        pos=used;
    }

    used+=qtty;

    if( used > size)
    {
        size=used+5;
        p_aux=new int[size];

        memcpy(p_aux, p, pos * sizeof(int) ); //copio hasta pos
        memcpy(p_aux+pos+qtty, p+pos , (aux-pos) * sizeof(int) );

        delete[]p;
        p=p_aux;

    }
    else
    {
        memcpy(p+pos+qtty, p+pos, aux * sizeof(int) );
    }

    memcpy(p + pos, vec, qtty * sizeof(int));
}
