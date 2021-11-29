#include<iostream>
using namespace std;

class Outer
{

public:
    class Nested
    {
    public:
        void MsgN()
        {
            cout<<"Hey from Nested Class"<<endl;
        }
    };

    void MsgO()
    {
        cout<<"Hey from Outer Class"<<endl;
    }
};


int main()
{
    Outer o;
    o.MsgO();
    Outer::Nested n;
    n.MsgN();
    return 0;
}
