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
    Beware of overflow - int 1e9 + int 1e9 == long long
*/

void solve()
{
    int n;
    cin>>n;

    ll arr[2][n+1];

    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    ll dp[2][n];

    //init with min value bcoz we need max value
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = INT_MIN;
        }
    }

    //first row first student height
    dp[0][0] = arr[0][0];

    //second row first student height
    dp[1][0] = arr[1][0];

    //for each student
    for(int i=1;i<n;i++)
    {
         //include from 1st row
         dp[0][i] = arr[0][i] + max(dp[0][i] , dp[1][i-1]);

         //include from 2nd row
         dp[1][i] = arr[1][i] + max(dp[1][i] , dp[0][i-1]);

         //dont include remains same as prev
         dp[0][i] = max(dp[0][i] , dp[0][i-1]);
         dp[1][i] = max(dp[1][i] , dp[1][i-1]);
    }

    cout<<max(dp[0][n-1] , dp[1][n-1]);

    return ;
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
    int t;
    t=1;
    //cin>>t;
    while(t-->0){
        solve();
    }
    return 0;
}
