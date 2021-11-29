
/*
 Problem-Hybrid Inheritance
 Contest-
*/


#include<bits/stdc++.h>
using namespace std;

class B
{
public:
    B()
    {
        cout<<"Base Class B"<<"\n";
    }
};

class D
{
public:
    D()
    {
        cout<<"Base Class D"<<"\n";
    }
};


class A:public B
{
    public:
    A()
    {
        cout<<"Derived Class A"<<"\n";
    }
};

class C:public B,public D
{
    public:
        C()
        {
            cout<<"Derived Class C"<<"\n";
        }
};

int main()
{
    A obj1;
    C obj2;
    return 0;
}

