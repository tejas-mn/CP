#include<iostream>
using namespace std;

class A
{
    /*Cannot initialize static non const member inside class*/
    static int counter;
    public:
        int static_incre()
        {
            counter++;
            return counter;
        }
};

/*Can initialize like this if counter is declared static*/
int A::counter=0;

int main()
{
    A a,b,c,d;

    /*On calling static_incre()
    on each object counter
    does not reset to zero
    its value does not change i.e it remains static*/

    cout<<a.static_incre()<<endl;
    cout<<b.static_incre()<<endl;
    cout<<c.static_incre()<<endl;
    cout<<d.static_incre()<<endl;
    return 0;
}
