#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define endl            "\n"
#define vi              vector<int>
#define pb              push_back
#define REP(a,b)        for(int i=a;i<=b;i++)
#define FAST_IO         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

/*****************************SOLVE HERE*******************************/

const int M = 1e9+7;

int binexp(int a, int b , int m)
{
    int res = 1;

    while(b>0){
        if(b&1){
            res = (res * a * 1LL) % m;
        }
        a = (a*a*1LL)%m;
        b>>=1;
    }

    return res;
}

const int N = 1e6 +7;
vector<int> fact(N);

void solve()
{

    //Ways to get N sized Password from K-Symbols
    //Choose N symbols from K symbols-->KcN
    //Now N symbols can be arranged in N! ways
    //Therefore ans is N! * KcN

    int n,k;
    cin>>n>>k;

    int ans  = fact[n];

    ans = (ans*1LL*fact[k])%M;

    int den  = (fact[k-n]*1LL*fact[n])%M;
    ans = (ans * 1LL *binexp(den,M-2,M))%M;
    cout<<ans<<endl;
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
    cin>>t;

    fact[0] = 1;
    for(int i=1;i<N;i++)
    {
        fact[i] = (fact[i-1] * i * 1LL)%M;

    }


    while(t--)
    {
        solve();
    }
    return 0;
}
