#include<iostream>
using namespace std;

class Average
{
    //Accessible by friend function
    private:int num1,num2;

    public:
        void getNum()
        {
            cout<<"Enter two numbers: ";
            cin>>num1>>num2;
        }
        friend float getAvg(Average a);
};

//Normal function defined as  friend uses class variables
float getAvg(Average a)
{
    return float(a.num1+a.num2)/2;
}


int main()
{
    Average a;
    a.getNum();
    cout<<"Average is: "<<getAvg(a);
    return 0;
}
