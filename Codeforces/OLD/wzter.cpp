#include<iostream>
using namespace std;

int main()
{
    int n,y,z,x;
    cin>>n;
    x=1;
    while(x)
    {
        y=2*x;
        z=n-y;
        if((y+z==n)&&(z>0))
        {
            //printf("%d %d\n",y,z);
            printf("YES\n");
            break;
        }
        else
        {
            //printf("%d %d\n",y,z);
            printf("NO\n");
            break;
        }

        x+=1;
    }
}
