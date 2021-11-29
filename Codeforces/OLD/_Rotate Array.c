#include<stdio.h>
int main()
{
    int i,n,r,arr[20],temp,testcase,count=0;
    scanf("%d",&testcase);
    while(count<testcase)
    {

    //printf("Enter the array size: ");
    scanf("%d %d",&n,&r);
    //printf("Rotate by? how many elements: ");
    //scanf("%d",&r);
    //printf("Enter the array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    /*printf("The array elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d \n",arr[i]);
    }*/

    temp=n-r;
    for(i=r;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    for(i=0;i<r;i++)
    {
        printf("%d ",arr[i]);
    }
    count++;
}
}
