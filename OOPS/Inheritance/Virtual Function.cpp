#include<iostream>
using namespace std;

class Base
{
    public:
        //Late binding with virtual else early binding
        virtual void fun()
        {
            cout<<"This is Base fun."<<endl;
        }

};

class Derived : public Base
{
    public:
        void fun()
        {
            cout<<"This is derived fun."<<endl;
        }
};
int main()
{
    Derived d;
    Base &b=d;
    b.fun();

    //Base *base_pointer=new Derived;
    //base_pointer->fun();

    return 0;
}
