#include "reparacion.h"

Reparacion::Reparacion(): Taller()
{
    Trabajos=nullptr;
    cant_arreglos=0;
    Costo_tot=0;
}

Reparacion::Reparacion(const string &marca, const string &mod, const string &pat, int hor, int min, int indc, int cant)
    : Taller( marca, mod, pat, hor, min)
{
    Trabajos=nullptr;
    cant_arreglos=0;
    Costo_tot=0;

    Tarea(indc, cant);
}

void Reparacion::Tarea(int indc, int cant)
{
    if(indc> 4 || indc <0)
    {
        cout<<"Error-indice incorrecto"<<endl;
        return;
    }

    if(cant_arreglos==0)
    {
        Trabajos= new Arreglo;
    }
    else
    {
        Arreglo *aux=Trabajos;

        Trabajos=new Arreglo [cant_arreglos +1 ];

        for(int i=0; i<cant_arreglos; i++)
            Trabajos[i]=aux[i]; //Son direcciones asi que no tengo que sobrecargar nada

        delete aux;
    }

    Trabajos[cant_arreglos].Cant=cant;
    Trabajos[cant_arreglos].Indice=indc;

    Costo_tot+=( Taller::Costo[indc] * cant);

    cant_arreglos++;
}

ostream& operator<< (ostream &c ,Reparacion& R )
{
    c<<(Taller &)R;
    c<<"------------"<<endl;
    for(int i=0; i<R.cant_arreglos; i++)
    {
        c<<"Tarea realizada :"<<Taller::Tarea[R.Trabajos[i].Indice]<<endl;
        c<<"Cantidad: "<<R.Trabajos[i].Cant<<endl;
        c<<"Costo parcial :"<<Taller::Costo[R.Trabajos[i].Indice]<<endl<<endl;
    }

    c<<"COSTO ACUMULADO: "<<R.Costo_tot<<endl<<endl;

    return c;
}
