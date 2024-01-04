#ifndef COMPLEJO_H
#define COMPLEJO_H


class Complejo
{
  private:
            float real;
            float imag;

  public:
            //Constructores

            Complejo();  //Constructor por defecto

            void set_Real(float r);
            void set_Imag(float i);
            float get_real();
            float get_imag();
            //float get_Modulo();
};

#endif // COMPLEJO_H
