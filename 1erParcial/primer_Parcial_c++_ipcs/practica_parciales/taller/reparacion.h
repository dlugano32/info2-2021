#ifndef REPARACION_H
#define REPARACION_H

#include "taller.h"

class Reparacion : public Taller
{
    private:

        struct Arreglo
        {
            int Indice;// indice de la tabla
            int Cant; //cantidad de repuestos de la tarea
        } *Trabajos;

        int cant_arreglos; //Cantidad total de arreglos en el vehículo
        int Costo_tot;//costo total= Costo del ítem * Cant de repuestos

    public:
        Reparacion();
        Reparacion(const string&,const string&,const string&,int,int,int,int); //marca, modelo,patente,hora,min,indice,cantidad de rep

        void Tarea(int,int) ;// se carga el indice cada tarea y la cant de repuestos y muestra en pantalla la tarea y los costos parciales y totales

        friend ostream& operator<< (ostream & ,Reparacion& );


};

#endif // REPARACION_H
