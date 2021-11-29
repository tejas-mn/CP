#include<iostream>
using namespace std;

int main()
{
    int n,t,global_count=0;
    cin>>n;
    t=n;
    int m[n][3];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&m[i][j]);
        }
    }
    for(int i=0;i<t;i++)
    {
        int cnt=0;
        for(int j=0;j<3;j++)
        {
            if(m[i][j]==1)
            {
                cnt+=1;
            }
            //printf("%d ",m[i][j]);
        }

        if(cnt>=2)
        {
            global_count+=1;
        }
        //printf("%d\n",cnt);
        //printf("\n");
    }
    printf("%d",global_count);

    return 0;
}
