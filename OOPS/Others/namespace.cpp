#include<iostream>
using namespace std;

namespace one{

    void fun1()
    {
        cout<<"Namespace 1"<<"\n";
    }
}

namespace two
{
    void fun2()
    {
        cout<<"Namespace 2"<<"\n";
    }
}
int main()
{
    one::fun1();
    two::fun2();

    return 0;
}
