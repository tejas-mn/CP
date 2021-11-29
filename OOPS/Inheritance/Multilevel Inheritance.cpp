
/*
 Problem-Multilevel Inheritance
 Contest-
*/


#include<bits/stdc++.h>
using namespace std;

class C
{
public:
    int x;
    C()
    {
        cout<<"Base Class C"<<"\n";
    }
};


class B:public C
{
    public:
        int y;
    B()
    {
        cout<<"Base Class B"<<"\n";
    }
};

class A:public B
{
    public:
        int z;
        A()
        {
            cout<<"Derived Class A"<<"\n";
        }
};

int main()
{
    A obj;
    cout<<&obj.C::x<<" "<<&obj.B::y<<" "<<&obj.A::z;
    return 0;
}

