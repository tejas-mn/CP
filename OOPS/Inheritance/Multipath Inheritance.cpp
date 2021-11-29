
/*
 Problem-Multipath Inheritance
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
    B()
    {
        cout<<"Base Class B"<<"\n";
    }
};


class C:public A
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

    /*x is ambiguous as compiler doesn't know through which path(i.e class B or C) to access x.
    There are two copies of x */

    //obj.A::x=1;
    //cout<<obj.x;
    //cout<<&obj.A::x<<"\n\n";

    //x=10 when accessed through class B
    obj.B::x=10;
    cout<<"\nB::x="<<obj.B::x<<"\n";
    cout<<&obj.B::x<<"\n\n";

    //x=100 when accessed through class C
    obj.C::x=100;
    cout<<"C::x="<<obj.C::x<<"\n";
    cout<<&obj.C::x<<"\n\n";

    return 0;
}
