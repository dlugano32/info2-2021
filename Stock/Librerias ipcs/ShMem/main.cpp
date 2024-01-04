#include "shmem.h"

int main(void)
{
    string mensaje="Hola mundi";
    char recibido[15];
    string a=".";
    int recepcion;

    ShMem Q( (char*) a.data() , 'a' , 15, false);

    if(Q.GetID()!=-1)
        cout<<"Conectado a la shared memory ID: "<<Q.GetID()<<endl;
    else
    {
        cout<<"No se pudo conectar a la shared memory"<<endl;
        return 0;
    }

    if( fork()!=0 ) //Proceso padre
    {

        if( Q.escribir((void *) mensaje.data(), mensaje.size(), 0) )
        {
            cout<<"Padre: Mensaje enviado"<<endl;
        }
        else
        {
            cout<<"Padre: Mensaje NO enviado"<<endl;
        }

        Q.SetBorrar(true);

        wait(NULL);
    }
    else
    {
        recepcion=Q.leer(recibido, 10, 0);

        printf("HIJO:");
        for(int i=0; i<10; i++)
        {
            printf("%c", recibido[i]);
        }
        printf("\n");

        cout<<"HIJO: Bytes recibidos :"<<recepcion<<endl;
    }

    return 0;
}
