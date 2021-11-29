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

void solve()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    //min number of rests till ith day by doing either
    //dp[i][0] = rest , dp[i][1] = contest , dp[i][2] = gym
    int dp[120][3];


    //Initialization - To find min initialize dp table to some max value
    for(int i=0;i<n;i++) dp[i][0] = dp[i][1] = dp[i][2] = 999;

    //Base Case(s) - Checking what can be done on day 0

        // he can always rest on day 0
        dp[0][0]=1;

        //Check if we can do a contest on day 0 then he cannot rest
        if(arr[0]==1 || arr[0]==3)
            dp[0][1] = 0;

        //Check if we can do a gym on day 0 then he cannot rest
        if(arr[0]==2 || arr[0]==3)
            dp[0][2]=0;


    //For rest of the days calculate min number of rests till ith day by doing either
    //dp[i][0] = rest , dp[i][1] = contest , dp[i][2] = gym
    //Same as base cases but here we take min of previous values for i days

    for(int i=1;i<n;i++)
    {
        //He can always rest on ith day
        dp[i][0] = 1 + min({dp[i-1][0] , dp[i-1][1] , dp[i-1][2]});

        //Check if we can do a contest on ith day
        //previous day cannot be contest so only calculate min of rest & gym
        if(arr[i]==1 || arr[i]==3)
            dp[i][1] = min(dp[i-1][0] , dp[i-1][2]);

        //Check if we can do a gym on ith day
        //previous day cannot be gym so only calculate min of rest & contest
        if(arr[i]==2 || arr[i]==3)
            dp[i][2]=min(dp[i-1][0] , dp[i-1][1]);
    }

    //Finally print min rest days  done by either of the  tasks
    cout<<min({dp[n-1][0] , dp[n-1][1] , dp[n-1][2]})<<endl;

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
