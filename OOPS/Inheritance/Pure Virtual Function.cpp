#include<iostream>
using namespace std;

//Abstract class
class Animal
{
    public: virtual void fun()=0;
};

void Animal::fun()
{
    cout<<"This is Animal."<<endl;
}

class Cow : public Animal
{
    public:
        void fun()
        {
            Animal::fun();
            cout<<"I eat veg."<<endl;

        }
};

class Snake : public Animal
{
    public:
        void fun()
        {
            cout<<"I eat both veg and non veg."<<endl;
        }
};

int main()
{

    //Animal a;
    Cow c;
    c.fun();
    return 0;
}
