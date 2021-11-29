#include<iostream>
using namespace std;

class Base
{
    public:
        virtual void fun()
        {
            cout<<"This is Base class fun."<<endl;
        }
};

class Derived1 : public Base
{
    public : void fun()
        {
            cout<<"This is Derived1 fun."<<endl;
        }

};

class Derived2 : public Base
{
    public : void fun()
            {
                cout<<"This is Derived2 fun."<<endl;
            }
};

void f(Base &r)
{
    r.fun();
}

int main()
{
    Base b;
    Derived1 d1;
    Derived2 d2;

    f(b);
    f(d1);
    f(d2);

    return 0;
}
