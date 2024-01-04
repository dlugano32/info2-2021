#include "poligono.h"

int Poligono::m_cantidadDePoligonos=0;  //Lo seteo en cero para arrancar a contar


Poligono::Poligono(int numeroDeLados)
{
    if(numeroDeLados >=3 )
    {
        m_vertices= new Punto [numeroDeLados];  //Reservo en memoria objetos de tipo punto
        cant=numeroDeLados;
        m_verticesIncorporados=0;   //Si bien tengo reservado el espacio para 3 puntos, no ingrese ninguno todavia
        m_cantidadDePoligonos++;
    }
    else
    {
        cout<<"El poligono debe tener mas de 3 vertices"<<endl;
        m_vertices=nullptr;
        m_verticesIncorporados=0;
    }
}

Poligono::~Poligono()
{
    if(m_vertices!=nullptr)
        delete [] m_vertices;   //Libero memoria
    m_cantidadDePoligonos--;    //Aca tengo en cuenta que el usuario quiere saber todo el tiempo cuantos objetos instanciados hay
}

const Punto &Poligono::getVertice(int numeroDeVertice) const    //Aca tengo en cuenta que el usuario va a pedirme los vertices empezando por el 1 y no por el 0
{
    if(numeroDeVertice > m_verticesIncorporados)
    {
       numeroDeVertice=m_verticesIncorporados;  //Osea le asigno el ultimo vertice
    }
    else if(numeroDeVertice <=0)    //en este caso le asigno el 1 para que no haya segmentation fault
    {
        numeroDeVertice=1;
        cout<<"Asignar numeros del 1 a n-lados"<<endl;
    }

    return m_vertices[numeroDeVertice -1]; // Si el usuario cuenta los puntos como 1..2..3

    //Puedo devolver el punto de esta manera ya que la misma definicion de la funcion me esta diciendo que no puede ser escrito,  solo leido. Porque es const Punto
}

Poligono &Poligono::operator <<(const Punto & p)
{

    if(cant > m_verticesIncorporados +1)    //Es decir, que si le agrego un elemento mas a mi vector, habria un overflow
    {
        Punto * aux= new Punto [cant + 1];

        for(int i=0; i<m_verticesIncorporados; i++)
        {
            aux[i]=m_vertices[i];   //Copio todo tal cual como era mi poligono antes
        }

        delete [] m_vertices;
        m_vertices=aux;
        cant ++;
    }
        m_vertices[m_verticesIncorporados]=p;   //Si todavia tengo espacio en mi vector
        m_verticesIncorporados++;

    return *this;
}

Poligono &Poligono::operator =(const Poligono &P)
{
    if(P.m_verticesIncorporados >=3)
    {
        delete [] m_vertices;   //Primero que nada libero memoria del poligono anterior

        m_verticesIncorporados=P.m_verticesIncorporados;
        cant=P.cant;
        m_vertices=new Punto [cant];

        for(int i=0; i<m_verticesIncorporados; i++)
        {
            m_vertices[i]=P.m_vertices[i];  //Usando el operador = que implemente
        }
    }
    else
        cout<<"Error-El poligono que ingreso no tiene mas de 3 lados"<<endl;

    return *this;
}

Poligono &Poligono::operator -=(const Punto & p)
{
    bool find =false;

    if(m_verticesIncorporados!=0)
    {
        //Primero me fijo si el punto que quiero sacar esta en mi poligono
        for(int i=0; i<m_verticesIncorporados; i++)
        {
            if(m_vertices[i]==p)
            {
                find=true;
            }
        }

        if(find)
        {
            Punto * aux= new Punto [cant];  //Mi vector va a tener el mismo tamaño, solo quiero sacar un objeto

            for(int i=0, j=0; i<m_verticesIncorporados; i++)
            {
                if(m_vertices[i]==p)
                {
                }
                else
                {
                    aux[j]=m_vertices[i];   //Guardo en aux todos los puntos menos el que quiero sacar
                    j++;
                }
            }

            delete [] m_vertices;
            m_vertices=aux;
            m_verticesIncorporados--;
        }
        else
        {
            cout<<"Error-El vertice ingresado no se encuentra en el poligono"<<endl;
        }
    }
    else
        cout<<"Error-El poligono aun no tiene vertices"<<endl;

    return *this;
}

ostream & operator << (ostream &c, const Poligono &P)
{
    c<<"\nPoligono\n";

    for(int i=0; i<P.m_verticesIncorporados; i++)
    {
        c<<"Punto N°"<<i+1<<" : "<<P.m_vertices[i]<<endl; //El punto tiene el operador << sobrecargado tambien
    }

    return c;
}



