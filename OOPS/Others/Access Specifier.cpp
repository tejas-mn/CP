#include<iostream>

using namespace std;

class A
{
    /*Accessible only inside class*/
    private:
        void fun1()
        {
            printf("Class A private\n");
        }
    /*Accessible outside class*/
    public:
        void fun2()
        {
            printf("Class A public\n");
        }
    /*Accessible by derived class and friend class,function..*/
    protected:
        void fun3()
        {
            printf("Class A protected\n");
        }

};


class B: public A
{
    public:
        void fun4()
        {

            fun2();
            fun3();
            printf("Class B public\n");
        }
};

int main()
{
    B b;
    b.fun4();
    b.fun2();
    return 0;
}
