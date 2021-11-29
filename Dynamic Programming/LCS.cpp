#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define endl            "\n"
#define vi              vector<int>
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define count(v,n)      count(all(v), n)
#define FOR(a,b)        for(int i=a;i<=b;i++)
#define minv(v)         *min_element(all(v))
#define maxv(v)         *max_element(all(v))
#define FAST_IO         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int inf           =1e9 + 10;
const unsigned int M    =1000000007;
const int mod           =1e9+7;
const int INF           =0x3f3f3f3f;
const ll llINF          =9223372036854775807;
const int N             =1e5+10;

/*****************************SOLVE HERE*******************************/

/*
//Recursive
int LCS(string x, string y , int n, int m)
{
    //Base Case - LCS of string length 0 is 0
    if(n==0 || m==0)
        return 0;

    //Choice Diagram

    //if last characters are equal
    if(x[n-1] == y[m-1]){

        //count 1 and call lcs by decreasing lengths of both strings
        return 1 + LCS(x,y,n-1,m-1);
    }
    else
    {
        //else you  have to pick max of two choices
        //keep first string as it is and reduce 2nd string or vice versa

        return max(LCS(x,y,n,m-1) , LCS(x,y,n-1,m));
    }
}
*/

/*
//Memoize + pass by reference(to avoid creating multiple copies saves time)
int dp[1000][1000];
void *addr = memset(dp , -1 , sizeof(dp));

int LCS(string &x, string &y , int n, int m)
{
    //Base Case - LCS of string length 0 is 0
    if(n==0 || m==0)
        return 0;

    if(dp[n][m]!=-1) return dp[n][m];

    //Choice Diagram

    //if last characters are equal
    if(x[n-1] == y[m-1]){

        //count 1 and call lcs by decreasing lengths of both strings
        return dp[n][m]  = 1 + LCS(x,y,n-1,m-1);
    }
    else
    {
        //else you  have to pick max of two choices
        //keep first string as it is and reduce 2nd string or vice versa

        return dp[n][m] = max(LCS(x,y,n,m-1) , LCS(x,y,n-1,m));
    }
}
*/


//DP
int LCS(string x, string y , int n, int m)
{
    //Base Case - LCS of string length 0 is 0

    int dp[n+1][m+1];
    void *addr = memset(dp , -1 , sizeof(dp));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)
            dp[i][j] = 0;
        }
    }

    //Choice Diagram

    //if last characters are equal
    for(int i=1;i<=n;i++)
    {

    for(int j=1;j<=m;j++)
    {


        if(x[i-1] == y[j-1]){

            //count 1 and call lcs by decreasing lengths of both strings
            dp[i][j]  = 1 + dp[i-1][j-1];
        }
        else
        {
            //else you  have to pick max of two choices
            //keep first string as it is and reduce 2nd string or vice versa

            dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
        }

    }
    }

    return dp[n][m];
}

/*****************************MAIN*************************************/
int main()
{
    FAST_IO;
/****************************STDIN/STDOUT******************************/
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
/******************************WRITE HERE*********************************/

    string x,y;
    cin>>x>>y;

    int n=x.size();
    int m=y.size();

    cout<<LCS(x , y , n , m);

    return 0;
}
