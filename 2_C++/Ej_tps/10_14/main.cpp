#include "intarr.h"

using std::cout;
using std::endl;
#define PRESS_KEY std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();


int main(void)
{
    int v_aux[]={0,5,10,15,20,25,30,35,40};
    IntArr A(10,sizeof(v_aux)/sizeof(int),v_aux);
    cout<<" size:"<<A.getSize()<<endl<<" used:"<<A.getUsed()<<endl;
    A.prtArr();
    A.addElement(77);
    cout<<" size:"<<A.getSize()<<endl<<" used:"<<A.getUsed()<<endl;
    A.prtArr();
    A.addElement(11);
    cout<<" size:"<<A.getSize()<<endl<<" used:"<<A.getUsed()<<endl;
    A.prtArr();
    A.addElement(8,v_aux);
    cout<<" size:"<<A.getSize()<<endl<<" used:"<<A.getUsed()<<endl;
    A.prtArr();
    PRESS_KEY;
}
