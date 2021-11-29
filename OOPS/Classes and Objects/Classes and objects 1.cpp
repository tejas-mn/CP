#include<iostream>
using namespace std;

/*Class Definition*/

class ClassA
{
    private:int a;
            int b;

    public: void getvalue(int,int);
            void showvalue();
};

/*Defining member function outside the class

return_type classname :: member_function()*/

void ClassA::getvalue(int i,int j)
{
    a=i;
    b=j;
}

void ClassA::showvalue()
{
    cout<<"a="<<a<<"\n";
    cout<<"b="<<b<<"\n";
}

int main()
{
    /*Creating object - classname objectname*/

    ClassA a;

    /*Calling methods - objectname.memberfunction()*/

    a.getvalue(5,10);
    a.showvalue();

    return 0;
}
