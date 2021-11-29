
/*
 Problem-Hierarchical Inheritance
 Contest-
*/


#include<bits/stdc++.h>
using namespace std;

class B
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
        int x;
        A()
        {
            cout<<"Derived Class A"<<"\n";
        }
};

class C:public B
{
    public:
        int z;
        C()
        {
            cout<<"Derived Class C"<<"\n";
        }
};

int main()
{
    A obj1;
    cout<<&obj1.A::x<<" "<<&obj1.B::y<<"\n";
    C obj2;
    cout<<&obj2.C::z<<" "<<&obj2.B::y<<"\n";

    return 0;
}

