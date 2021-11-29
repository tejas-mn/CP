#include<iostream>
using namespace std;

class A
{
    public:

        void fun(const int arr[])
        {
            for(int i=0;i<5;i++)
            {
                /*Cannot modify arr since it is declared const*/
                arr[i]=arr[i]+arr[i];
            }
        }
};

int main()
{
    int arr[]={1,2,3,4,5};
    A a;
    a.fun(arr);
    for(int x:arr)
    {
        cout<<x<<endl;
    }
    return 0;
}
