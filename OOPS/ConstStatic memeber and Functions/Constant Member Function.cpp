#include<iostream>

using namespace std;


class A
{

    public:
        int x;

        A(){
        x=10;
        }

        //Constant member function cannot modify any data member
        void fun() const
        {
            x+=1;
        }

        void show()
        {
            printf("X is %d ",x);
        }
};

int main()
{
    A a;
    a.fun();
    a.show();
    return 0;

}
