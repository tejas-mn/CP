#include<bits/stdc++.h>
using namespace std;

//TopDown
int CountSubsetSum(int arr[], int n, int sum)
{
    //dp table
    int t[n+1][sum+1];

    //BaseCase--> Initialization of first row first column
    //(n,sum)=>(i,j)
    //n==0 and sum>0 ->false
    //n>=0 and sum==0 ->true empty subset{} gives sum 0 for any n


    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
                t[i][j] = 0;
            if(j==0)
                t[i][j] = 1;
        }
    }

    //ChoiceDiagram-->Recursive->Iterative

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            //if (n-1)th number is less than sum we can include or exclude
            if(arr[i-1]<=j)
                t[i][j] = (t[i-1][j-arr[i-1]]) + (t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }

    return t[n][sum];
}

int countDiff(int arr[] , int n, int diff)
{
    int arraysum =0;
    for(int i=0;i<n;i++) arraysum+=arr[i];

    if((diff+arraysum)&1)
        return 0;

    int sum = (diff + arraysum)/2;

    return CountSubsetSum(arr , n ,sum);
}


/*****************************MAIN*************************************/
int main()
{

/****************************STDIN/STDOUT******************************/
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
/******************************WRITE HERE*********************************/

    int arr[1000];
    int n;
    cin>>n;

    for(int i=0;i<n;i++) cin>>arr[i];
    int diff;
    cin>>diff;

    cout<<countDiff(arr , n , diff)<<endl;

    return 0;
}
