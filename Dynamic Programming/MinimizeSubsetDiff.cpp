#include<bits/stdc++.h>
using namespace std;

vector<int> SubsetSum(int arr[], int n, int sum)
{

    bool t[n+1][sum+1];

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

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
                t[i][j] = (t[i-1][j-arr[i-1]]) or (t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }

    vector<int> v;
    for(int i=n;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(t[i][j])
                v.push_back(j);
        }
    }

    return v;
}

int minDiff(int arr[] , int n)
{
    int sum = 0;
    for(int i=0;i<n;i++) sum+=arr[i];

    int diff = INT_MAX;
    for(auto x : SubsetSum(arr , n ,sum/2))
    {
        diff = min(diff , sum-(2*x));
    }

    return diff;
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

    cout<<minDiff(arr , n);
    return 0;
}
