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
    size=sz;
    p=new int[size];
    used=qtty;

    if(qtty>sz)
    {
        qtty=sz;
    }

    for(int i=0; i<size; i++)   //lo inicializo en 0
    {
        p[i]=0;
    }

    for(int i=0; i<qtty ; i++)
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

void IntArr::addElement (int val)
{
    int *aux=nullptr;

    if(used==size)
    {
        size+=6;
        aux= new int[size]; // se le agrega uno para usar y 5 de forma preventiva

        for(int i=0; i<used; i++)
        {
            aux[i]=p[i];
        }

        delete[]p;
        p=aux;
    }
    used++;
    p[used-1]=val;

}
void IntArr::addElement (int qtty, int *vec)
{
    int *aux=nullptr;

    if( (used+qtty) > size)
    {
        size=used+qtty+5;
        aux=new int[size];

        for(int i=0; i<used; i++)
        {
            aux[i]=p[i];
        }

        delete[]p;
        p=aux;
    }

    for(int i=0; i<qtty; i++)
    {
        p[used+i]=vec[i];
    }

    used+=qtty;
}
