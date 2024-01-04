#include "vacuna.h"
using namespace std;

Vacuna::Vacuna(int temp, int min, int seg, bool est)
{
    temperatura=temp;
    minutos=min;
    segundos=seg;
    estado=est;

    checkTime();
    checkEstado();
}

Vacuna::Vacuna(const Vacuna & vac){

    temperatura=vac.temperatura;
    minutos=vac.minutos;
    segundos=vac.segundos;
    estado=vac.estado;

}

void Vacuna::checkEstado()
{
    if (estado==true){
        if(minutos>3 || (minutos==3 && segundos>25)){
            if (temperatura>-50){
                estado=false;
            }
        }
    }
}

void Vacuna::checkTime()
{
    if(segundos >=60)
    {
           minutos+=segundos/60;
           segundos=segundos%60;
    }
}

void Vacuna:: setTemp(int a){
    temperatura=a;
}

void Vacuna:: setMin(int a){
    minutos=a;
}

void Vacuna:: setSeg(int a){
    segundos=a;
    checkTime();
}

void Vacuna:: setEst(bool e){
    estado=e;
}

void Vacuna:: setVacuna(int temp,int min, int seg, bool est){

    setTemp(temp);
    setMin(min);
    setSeg(seg);
    setEst(est);

    checkEstado();
}

int Vacuna:: getTemp() const{
    return temperatura;
}

int Vacuna:: getMin() const{
    return minutos;
}

int Vacuna:: getSeg() const{
    return segundos;
}

bool Vacuna:: getEst() const{
    return estado;
}

string Vacuna:: getVacuna () const{
    string str;

    str=to_string(temperatura)+";"+to_string(minutos)+";"+to_string(segundos)+";"+(estado?"OK":"ERROR");

    return str;
}

Vacuna & Vacuna::operator =(const Vacuna &vac)
{
    temperatura=vac.temperatura;
    minutos=vac.minutos;
    segundos=vac.segundos;
    estado=vac.estado;

    return *this;
}

void Vacuna ::operator +=(int segs)
{
    segundos+=segs;

    checkTime();
}

void Vacuna::operator ++(int)
{
    *this+=1;
}

bool Vacuna::operator <(const Vacuna &vec)
{
    bool aux=false;

    if(minutos < vec.minutos || (minutos == vec.minutos &&  segundos < vec.segundos) )
    {
        aux=true;
    }

    return aux;
}

bool Vacuna:: operator >(const Vacuna &vec)
{
    bool aux=true;

    if(*this < vec)
    {
        aux=false;
    }

    return aux;
}

bool Vacuna::operator ==(const Vacuna &vec)
{
    bool aux=false;

    if( (minutos == vec.minutos) && (segundos== vec.segundos) )
    {
        aux=true;
    }

    return aux;
}

ostream & operator <<(ostream &c, const Vacuna &vec)
{
    c<<"{"<<vec.getVacuna()<<"}";

    return c;
}
