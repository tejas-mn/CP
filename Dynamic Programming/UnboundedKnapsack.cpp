#include<bits/stdc++.h>
using namespace std;


int UnboundedKnapsack( int wt[] , int val[], int W , int n)
{
    //dp table with states
    int t[n+1][W+1];
    memset(t, -1 , sizeof(t));


    //Initialization

    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0 || j==0)
                t[i][j]=0;
        }
    }

    //Choice Diagram

    for(int i=1;i<n+1;i++)
    {

        for(int j=1;j<W+1;j++){

            if(wt[i-1]<=j)
            {
                t[i][j] = max( val[i-1] + t[i][j-wt[i-1]] , t[i-1][j]);
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
        }
    }


    return t[n][W];

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

    int n,W;
    int wt[1000],val[1000];

    cin>>n>>W;
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    for(int i=0;i<n;i++){
        cin>>val[i];
    }

    cout<<UnboundedKnapsack(wt , val , W , n);

    return 0;
}
