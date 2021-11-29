#include<iostream>
using namespace std;

int main()
{

    int n,k,cnt=0;
    int kth_score;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    kth_score=a[k-1];
    //printf("kth score %d",kth_score);
    for(int i=0;i<n;i++)
    {
        if((a[i]>=kth_score))
        {
            if(a[i]!=0)
            {
                    cnt+=1;
            }

        }
    }
    printf("%d",cnt);

    return 0;
}
