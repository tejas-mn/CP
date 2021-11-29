#include<iostream>
using namespace std;

int main()
{
    int n,y,z;
    int x=1;

    scanf("%d",&n);
    //While loop to generate pairs y,z
    while(x)
    {
        y=x*2;
        z=n-y;
        if((y%2==0) && (z%2==0) && (z>0))
        {
            printf("%d %d ",y,z);
            printf("YES\n");
            //break;
        }
        else
        {
            printf("%d %d ",y,z);
            printf("NO\n");
            break;
        }
        x+=1;
    }
}
