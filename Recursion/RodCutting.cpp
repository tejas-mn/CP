#include<bits/stdc++.h>
using namespace std;


/*****************************SOLVE HERE*******************************/

//returns max no . of pieces that can be cut in denominations of a,b,c
int RodCut(int n , int a , int b ,int c)
{
    //base case
    if(n==0) return 0;
    if(n<0) return -1;

    //choice diagram - Calculate max ( pieces that can be obtained by making cut of either a or b or c)
    int res = max
              (
                {
                    RodCut(n-a , a, b, c),
                    RodCut(n-b , a , b , c),
                    RodCut(n-c , a , b ,c)
                }
              );

    //Corner case - n=9 a,b,c=2
    if(res==-1) return -1;

    return res+1;
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

    int n,a,b,c;
    cin>>n>>a>>b>>c;

    cout<<RodCut(n , a,b,c);
    return 0;
}
