//O(n) //O(1)

#include<stdio.h>

void swapp(int a[],int low,int high)
{
    int temp;
    temp=a[low];
    a[low]=a[high];
    a[high]=temp;
}

void rev(int a[],int low,int high)
{
    while(low<high)
    {
        swapp(a,low,high);
        low+=1;
        high-=1;
    }
}

int main()
{
    int a[5]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    rev(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}


//Recursive
#include<stdio.h>

void swapp(int a[],int low,int high)
{
    int temp;
    temp=a[low];
    a[low]=a[high];
    a[high]=temp;
}

void rev(int a[],int low,int high)
{
    if(low<high)
    {
        swapp(a,low,high);
        rev(a,low+1,high-1);
    }
}

int main()
{
    int a[5]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    rev(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}


//Using extra array


void rev(int a[],int n)
{
    int temp[n];

    for(int i=0;i<n;i++)
    {
        temp[i]=a[n-1-i];
    }
    for(int i=0;i<n;i++)
    {
        a[i]=temp[i];
    }
}
int main()
{
    int a[5]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    rev(a,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

//Using pointers
#include<stdio.h>
#include<stdlib.h>
void rev(int *a,int n)
{
    int *temp;
    temp=(int*)malloc((sizeof(int)*n));
    if(temp==NULL)
        exit(0);

    for(int i=n-1,j=0;i>=0;i--,j++)
        *(temp+j)= *(a+i);

    for(int i=0;i<n;i++)
        *(a+i)=*(temp+i);

    free(temp);
}
int main()
{
    int n,*a;
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    if(a==NULL)
        exit(0);

    for(int i=0;i<n;i++)
        scanf("%d",(a+i));

    rev(a,n);

    for(int i=0;i<n;i++)
        printf("%d ",*(a+i));

    free(a);
    return 0;
}
