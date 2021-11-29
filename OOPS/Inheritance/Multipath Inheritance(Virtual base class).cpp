
/*
 Problem-Multipath Inheritance(Using virtual base class)
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


class B:virtual public A
{
    public:
    B()
    {
        cout<<"Base Class B"<<"\n";
    }
};


class C:virtual public A
{
public:
    C()
    {
        cout<<"Base Class C"<<"\n";
    }
};

class D:public B,public C
{
    public:
        D()
        {
            cout<<"Derived Class D"<<"\n";
        }
};

int main()
{
    D obj;

    /*Now there is only one copy of x shared between all three classes and are overwritten.*/

    obj.A::x=10;
    cout<<"\nA::x="<<obj.x<<"\n";
    cout<<"Address of x:"<<&obj.A::x<<"\n\n";

    obj.B::x=100;
    cout<<"B::x="<<obj.B::x<<"\n";
    cout<<"Address of x:"<<&obj.B::x<<"\n\n";

    obj.C::x=1;
    cout<<"C::x="<<obj.C::x<<"\n";
    cout<<"Address of x:"<<&obj.C::x<<"\n\n";

    return 0;
}
