#include<bits/stdc++.h>
using namespace std;

bool SubsetSum(int arr[], int n, int sum)
{
    //dp table
    bool t[n+1][sum+1];

    //BaseCase--> Initialization of first row first column
    //(n,sum)=>(i,j)
    //n==0 and sum>0 ->false
    //n>=0 and sum==0 ->true empty subset{} gives sum 0 for any n


    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
                t[i][j] = false;
            if(j==0)
                t[i][j] = true;
        }
    }

    //ChoiceDiagram-->Recursive->Iterative

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            //if (n-1)th number is less than sum we can include or exclude
            if(arr[i-1]<=j)
                t[i][j] = (t[i-1][j-arr[i-1]]) or (t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }

    return t[n][sum];
}

bool isPartition(int n , int arr[])
{
    int sum=0;
    for(int i=0;i<n;i++) sum+=arr[i];

    //If sum is odd we cannot divide into two equal sum
    if(sum%2!=0) return false;

    //If sum is even we can have two equal sum(subset)
    //Eg if sum=22->>11 + 11 so there must be subset with sum 11
    //if there exists subset with sum=sum/2 then arr can be partitioned into two equal sum subset

    if(sum%2==0)
    {
        return SubsetSum(arr , n , sum/2);
    }
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
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    if(isPartition(n , arr)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    return 0;
}
