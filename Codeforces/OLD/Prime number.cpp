#include<iostream>
using namespace std;


int isPrime(int n)
{
    int flag=0;
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }

    if(flag==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int main()
{
    int m,n;
    int flag=0;
    cin>>n>>m;
    for(int i=n+1;i<2*n+m;i++)
    {
        if(isPrime(i))
        {
            if(i==m)
            {
                flag=1;
                break;
            }

        }
    }
    if(flag==0)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }


    return 0;
}
