
/*
 Problem-Single Inheritance
 Contest-
*/


#include<bits/stdc++.h>
using namespace std;

class A
{
public:
    int x;
    A()
    {
        cout<<"Base Class A"<<"\n";
    }
};


class B:public A
{
    public:

    int y;
    B()
    {
        cout<<"Derived Class B"<<"\n";
    }
};

int main()
{
    B obj;
    cout<<&obj.A::x<<" "<<&obj.B::y;
    return 0;
}

