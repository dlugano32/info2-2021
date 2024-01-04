#include "my_string.h"

my_string::my_string()
{
    inicio=nullptr;
    len=0;
    error=0;
}

my_string :: my_string(const int sz)    //Constructor parametrizado
{
    len=sz;
    inicio=new char[len + 1];   //Le agrego el null
    error=0;

}

my_string::my_string( const my_string& s)  //Constructor de copia
{
    error=0;
    len= s.len;

    inicio=new char[len];

    for(int i=0; i<len; i++)
    {
        inicio[i]=s.inicio[i];
    }

    inicio[len]='\0';

}

my_string::my_string(const char*s)
{
    int i=0;

    while(*(s+i)!='\0')
    {
        i++;
    }

    len=i;

    inicio=new char[len+1];

    for(int j=0; j<len; j++)
    {
        inicio[j]=*(s+j);
    }

    inicio[len]='\0';
}

//Metodos

int my_string::getLen(void) const
{
    return len;
}

my_string& my_string:: operator = (const my_string& s)
{
    delete[]inicio;

    len=s.len;

    inicio=new char [len];

    for(int i=0; i<len; i++)
    {
        inicio[i]=s.inicio[i];
    }

    inicio[len]='\0';

    return *this;
}

bool my_string ::operator == (const my_string &s) const
{
    bool aux=false;
    int i=0;

    while ( (*(inicio +i) == *(s.inicio + i) ) && aux==false)
    {
           if(*(inicio +i) == '\0' && *(s.inicio + i)=='\0')
           {
                 aux=true;
           }
           i++;
    }

    return aux;
}

bool my_string::operator != (const my_string &s) const
{

    bool aux=true;

    if( (*this) == s )  //Como ya cree el operador igual, entonces lo reutilizo
    {
         aux=false;
    }
    else
    {
        aux=true;
    }

    return aux;
}


char& my_string::operator [] (int pos)
{
    if(pos <= len && pos >=0 )
    {
        return inicio[pos];
    }
    else
    {
        return error;
    }
}

my_string my_string::operator + (const my_string & s) const
{
    my_string aux(len + s.len);

    for(int i=0; i<len; i++)
    {
        aux.inicio[i]=inicio[i];
    }

    for( int i=0; i<s.len; i++)
    {
        aux.inicio[i+len]=s.inicio[i];
    }
    aux.inicio[aux.len]='\0';

    return aux;
}

my_string& my_string:: operator += (const my_string &s)
{
    int n_sz=0;
    n_sz=len+s.len;

    char *aux=new char[n_sz+1];

    for(int i=0, j=0; i<n_sz; i++)
    {
        if(i<len)
        {
            aux[i]=inicio[i];
        }
        else if(i>=len)
        {
            aux[i]=s.inicio[j];
            j++;
        }
    }

    len=n_sz;
    aux[len]='\0';

    delete []inicio;
    inicio=aux;

    return *(this);
}

bool my_string::operator > (const my_string &s)const
{
    bool aux=false;

    int fin=1, i=0;

    while ( (*(inicio +i) == *(s.inicio + i) ) && fin==1)
    {
           if(*(inicio +i) == '\0' && *(s.inicio + i)=='\0')
           {
                  fin=0;
           }
           i++;
    }

    if(fin ==1) //Si fin = 0 ->La dif es cero y la condicion es falsa
    {
        if( *(inicio + i) > *(s.inicio + i) )
        {
         aux=true;
        }
    }

    return aux;

}

bool my_string::operator < (const my_string &s)const
{

    bool aux=false;

    if( *(this) > s)
    {
        aux=false;
    }
    else
    {
        aux=true;
    }

    return aux;

}

my_string my_string::mid(int inic, int fin)    //Cortar
{
    my_string ret(fin-inic);

    for(int i=0; i<ret.len; i++)
    {
        ret[i]=inicio[inic + i];
    }

    return ret;
}


my_string& my_string:: operator <<  (char valor)
{

        char *aux = new char (len+2);   //largo del string+char+null
        len++;

        for(int i=0; i<len; i++)
        {
            aux[i]=inicio[i];
        }

        if(inicio!=nullptr)
        {
            delete[]inicio;
        }

        aux[len-1]=valor;
        aux[len]='\0';
        inicio=aux;

    return *this;
}


ostream & operator << ( ostream &c, const my_string &s)
{
    c<<"'";

    for(int i=0; s.inicio[i]!='\0'; i++)
    {
        c<<s.inicio[i];
    }

    c<<"'"<<endl;
    return c;
}

my_string::~my_string()
{
    if(inicio!=nullptr)
    {
        delete[]inicio;
    }
}



