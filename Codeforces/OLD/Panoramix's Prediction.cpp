#include<iostream>
using namespace std;

int main()
{
    int m,n;
    int x,y,a,b;
    int flag=0;
    cin>>n>>m;

    for(int i=1;i<10;i++)
    {
        x=6*i-1;
        y=6*i+1;
        a=6*(i+1)-1;
        b=6*(i+1)+1;

        if((n==2 && m==3 )|| (n==3 && m==5) )
        {
            flag=1;
            break;
        }

        if((n==x && m==y )||( n==y && m==a )||(n==y && m==b))
        {
            flag=1;
            break;
        }
        if(n==x && m==a)
        {
            flag=0;
            break;
        }
    }

    if(flag==0)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }
    return 0;
}
