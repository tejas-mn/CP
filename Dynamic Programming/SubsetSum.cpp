#include<bits/stdc++.h>
using namespace std;

/*
//Recursion
bool SubsetSum(int arr[], int n, int sum)
{

    //BaseCase--> Initialization of first row first column
    if(n==0 && sum>0)
        return false;
    if(n>=0 && sum==0)
        return true;

    //ChoiceDiagram-->Recursive->Iterative

    //if (n-1)th number is less than sum we can include or exclude
    if(arr[n-1]<=sum)
        return SubsetSum(arr, n-1,sum-arr[n-1]) or SubsetSum(arr, n-1,sum);
    else
        return SubsetSum(arr , n-1 , sum);

}
*/

/*
//Memoize
int t[1000][100];
void *ptr = memset(t, -1 , sizeof(t));

bool SubsetSum(int arr[], int n, int sum)
{

    //BaseCase--> Initialization of first row first column
    if(n==0 && sum>0)
        return 0;
    if(n>=0 && sum==0)
        return 1;

    if(t[n][sum]!=-1)
        return t[n][sum];

    //ChoiceDiagram-->Recursive->Iterative

    //if (n-1)th number is less than sum we can include or exclude
    if(arr[n-1]<=sum)
        return t[n][sum] = (SubsetSum(arr, n-1,sum-arr[n-1]) || SubsetSum(arr, n-1,sum))?1:0;
    else
        return t[n][sum] = SubsetSum(arr , n-1 , sum);

}
*/


/*
//TopDown
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
*/



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
    int sum;
    cin>>sum;

    if(SubsetSum(arr, n , sum))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
