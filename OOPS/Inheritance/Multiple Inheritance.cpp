
/*
 Problem-Multiple Inheritance
 Contest-
*/


#include<bits/stdc++.h>
using namespace std;

class B
{
public:
    int x;
    B()
    {
        cout<<"Base Class B"<<"\n";
    }
};

class C
{
public:
    int y;
    C()
    {
        cout<<"Base Class C"<<"\n";
    }
};

class A:public B,public C
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
    cout<<&obj.B::x<<" "<<&obj.C::y<<" "<<&obj.A::z;
    return 0;
}

