#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream>
#include <cstring>
using namespace std;

class my_string
{
    private:
        int len;
        char *inicio;
        char error;

        int strlen(void);
    public:

    //Constructores

    my_string();    //Constructor por defecto
    my_string( const int);    //Constructor parametrizado
    my_string( const my_string& );  //Constructor de copia
    my_string( const char* );

    //Metodos de acceso

    int getLen(void) const;

    //Sobrecarga de operadores

    my_string& operator = (const my_string&);  //strcpy
    my_string operator + (const my_string &) const;   //strcat-devuelve un string nuevo con la concatenacion del objeto invocador+ el objeto por referencia
    my_string & operator += (const my_string &);
    char& operator [] (int);  //acceder

    //Comparacion
    bool operator == (const my_string &)const;   //strcmp
    bool operator != (const my_string &)const;
    bool operator > (const my_string &)const;
    bool operator < (const my_string &)const;

    my_string mid(int, int);    //Cortar

    my_string & operator <<  (char);   //le agrego un caracter al final del string

    friend ostream & operator << (ostream &, const my_string &);

    ~my_string();
};

ostream & operator << (ostream &, const my_string &);    //para imprimir el string

#endif // MY_STRING_H
