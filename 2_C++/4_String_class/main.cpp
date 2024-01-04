#include <iostream>
#include "my_string.h"

using namespace std;

int main()
{
    my_string A("holaa");

    if(A<"holas")
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }

    cout<<A;
}
