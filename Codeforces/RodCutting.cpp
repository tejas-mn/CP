#include<bits/stdc++.h>
using namespace std;

int RodCutting( int length[] , int n)
{
    int t[n+1][n+1];
    memset(t , -1  , sizeof(t));

    //Initialization
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){

            if(j==0)
                t[i][j]=0;

            if(i==0)
                t[i][j] = INT_MIN;
        }
    }

    //Choice Diagram
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(length[i-1]<=j)
            {
                t[i][j] =  max(1+ t[i][j-length[i-1]] , t[i-1][j]);
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][n];
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


    int n;
    cin>>n;

    int length[1000];

    for(int i=0;i<3;i++){
        cin>>length[i];
    }

    cout<<RodCutting(length , n)<<endl;
    return 0;
}
