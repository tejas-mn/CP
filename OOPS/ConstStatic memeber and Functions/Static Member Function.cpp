#include<iostream>
using namespace std;

class A
{
    /*Cannot initialize static non const member inside class*/
    static int counter;
    public:
        void static_inc()
        {
            counter++;
        }

        static int get_count()
        {
            return counter;
        }
};

/*Can initialize like this outside the class if counter is declared static*/
int A::counter=0;

int main()
{
    A a,b,c,d;

    /*On calling static_incre()
    on each object counter
    does not reset to zero
    its value does not change i.e it remains static*/

    cout<<"Before: "<<A::get_count()<<endl;

    a.static_inc();
    b.static_inc();
    c.static_inc();
    d.static_inc();

    cout<<"After: "<<A::get_count()<<endl;
    return 0;
}
