#include<iostream>
using namespace std;

class Country
{
    string name,capital,currency;

    public:
        void setData(string n,string cap,string cur);
        void getData();

};

void Country:: setData(string n,string cap,string cur)
{
    name=n;
    capital=cap;
    currency=cur;

}

void Country::getData()
{
    cout<<"Name: "<<name<<endl;
    cout<<"Capital: "<<capital<<endl;
    cout<<"Currency: "<<currency<<endl;
}


int main()
{

    Country c[2];

    string name,capital,currency;

    for(int i=0;i<2;i++)
    {
    cout<<"Enter the "<<i<<"th Country"<<endl;

    cout<<"Enter the country name"<<endl;
    cin>>name;

    cout<<"Enter the Capital"<<endl;
    cin>>capital;

    cout<<"Enter the currency"<<endl;
    cin>>currency;

    c[i].setData(name,capital,currency);

    }

    for(int i=0;i<2;i++)
    {
        c[i].getData();
    }

    return 0;

}
