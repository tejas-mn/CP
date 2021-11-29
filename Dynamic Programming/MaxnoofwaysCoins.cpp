#include<bits/stdc++.h>
using namespace std;



int MaxwaysCoins(int coins[] , int sum, int n)
{
    int t[n+1][sum+1];

    memset(t, -1 , sizeof(t));


    //Initialization
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0)
                t[i][j]=0;
            if(j==0)
                t[i][j]=1;
        }
    }

    //Choice Diagram
    for(int i=1;i<n+1;i++)
    {

        for(int j=1;j<sum+1;j++){

            if(coins[i-1]<=j)
            {
                t[i][j] =  t[i][j-coins[i-1]] + t[i-1][j];
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
        }
    }


    return t[n][sum];
}

int main()
{
    /****************************STDIN/STDOUT******************************/
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    /****************************STDIN/STDOUT******************************/

    int coins[1000];
    int n,sum;

    cin>>n>>sum;
    for(int i=0;i<n;i++) cin>>coins[i];

    cout<<MaxwaysCoins(coins , sum , n )<<endl;
    return 0;
}
