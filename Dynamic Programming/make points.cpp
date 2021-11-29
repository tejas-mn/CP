#include<bits/stdc++.h>
using namespace std;

long long int make(long long int n)
{
   long long int dp[n+1],i;
   memset(dp, 0, sizeof(dp));

   //basecase
   dp[0]=1;

   //recursive n->i

   //n..3 make(n-3)
   for(int i=3;i<=n;i++)
        dp[i]+=dp[i-3];     //return 1 + make(n-3);
   for(int i=5;i<=n;i++)
        dp[i]+=dp[i-5];
   for(int i=10;i<=n;i++)
        dp[i]+=dp[i-10];

   for(int i=0;i<=n;i++)
    cout<<dp[i]<<" ";
   cout<<endl;

   return dp[n];
}



void solve()
{
    int n;
    cin>>n;

    cout<<make(n);
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
    solve();
    return 0;
}
