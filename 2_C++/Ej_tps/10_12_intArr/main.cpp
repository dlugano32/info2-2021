#include "intarr.h"

using std::cout;
using std::endl;
#define PRESS_KEY std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();


int main(void)
{
    IntArr A(30);
    int v_aux[7]={23,4,54,634,6677,32,56};
    IntArr B(40,sizeof(v_aux)/sizeof(int),v_aux);
    A.prtArr();
    B.prtArr();
    PRESS_KEY;
}
