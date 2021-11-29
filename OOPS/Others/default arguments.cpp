#include<iostream>
using namespace std;

float interest(int ,int,float);

float interest(int p,int t=1,float r=2.5)
{
    cout<<"p: "<<p<<endl;
    cout<<"t: "<<t<<endl;
    cout<<"r: "<<r<<endl;
    return (p*t*r)/100;
}

int main()
{
    cout<<"Interest: "<<interest(1000)<<endl;
    cout<<"Interest: "<<interest(1000,5)<<endl;
    cout<<"Interest: "<<interest(1000,5,7.5)<<endl;

    return 0;

}
