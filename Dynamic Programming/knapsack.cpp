#include<bits/stdc++.h>
using namespace std;

//DP=Recursive->Memoization->Bottomup(dp Table)

/*
//Recursive
int KnapSack(int wt[], int val[], int n, int W)
{
    //BaseCase-Think of least valid input
    //No items(n==0) or No bag(W==0) then profit is 0
    if(n==0 || W==0)
        return 0;

    //Recursive Solution-Choice diagram

    //If weight of item <= Capacity
    //Then item can be included or not included
    if(wt[n-1] <= W)
    {
        //return MaxProfit
        return max(

            //If (n-1)th item is included
            //Then profit of that item + profit of remaining (n-1) items
            val[n-1] + KnapSack(wt , val , n-1, W-wt[n-1]),

            //If (n-1)th item is excluded
            KnapSack(wt, val, n-1, W)

        );
    }
    else

    //If weight of item > Capacity
    if(wt[n-1]>W)
    {
        //Return profit for rest of the (n-1) items
        return KnapSack(wt, val, n-1, W);
    }

}
*/


/*
//Memoization
int  t[200][200];
void *adrs = memset(t , -1 , sizeof(t));

int KnapSack(int wt[], int val[], int n, int W)
{
    //BaseCase-Think of least valid input
    //No items(n==0) or No bag(W==0) then profit is 0
    if(n==0 || W==0)
        return 0;

    if(t[n][W] != -1)
        return t[n][W];

    //Recursive Solution-Choice diagram

    //If weight of item <= Capacity
    //Then item can be included or not included
    if(wt[n-1] <= W)
    {
        //return MaxProfit
        return t[n][W] =  max(

            //If (n-1)th item is included
            //Then profit of that item + profit of remaining (n-1) items
            val[n-1] + KnapSack(wt , val , n-1, W-wt[n-1]),

            //If (n-1)th item is excluded
            KnapSack(wt, val, n-1, W)

        );
    }
    else

    //If weight of item > Capacity
    if(wt[n-1]>W)
    {
        //Return profit for rest of the (n-1) items
        return t[n][W] = KnapSack(wt, val, n-1, W);
    }

}
*/

/*
//Topdown
int KnapSack(int wt[], int val[], int n, int W)
{
    //DP table
    int  t[n+1][W+1];
    memset(t , -1 , sizeof(t));


    //Base Case -> Initialization (n==0,W==0)=> t(i==0,j==0)
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0 || j==0)
                t[i][j]=0;
        }
    }

    //Recursive Solution -> Iterative Solution
    //(n,W)->(i,j)


    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<W+1;j++)
        {
            //If weight of item <= Capacity
            //Then item can be included or not included
            if(wt[i-1] <= j)
            {
                //return MaxProfit
                t[i][j] =  max(

                    //If (n-1)th item is included
                    //Then profit of that item + profit of remaining (n-1) items
                    val[i-1] + t[i-1][j-wt[i-1]],

                    //If (n-1)th item is excluded
                    t[i-1][j]

                );
            }
            else

            //If weight of item > Capacity
            //if(wt[i-1]>W)
            {
                //Return profit for rest of the (n-1) items
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][W];
}
*/

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


    int n,W;
    cin>>n>>W;

    int wt[n+2],val[n+2];

    for(int i=0;i<n;i++) cin>>val[i];
    for(int i=0;i<n;i++) cin>>wt[i];

    cout<<KnapSack( wt,  val,  n,  W)<<endl;

    return 0;

}
