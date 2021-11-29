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

const int inf = 1e9 + 10;
const unsigned int M = 1000000007;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll llINF = 9223372036854775807;
const int N = 1e5+10;

/*****************************SOLVE HERE*******************************/

/*
//recursive
int cut(int n , int a , int b , int c)
{
    if(n==0) return 0;

    if(n<0) return INT_MIN;

    return 1 + max( cut(n-a,a,b,c) , max(cut(n-b,a,b,c),cut(n-c,a,b,c)) );
}
*/

/*
//memoize-bottom up
int t[10000];
void *adrs = memset(t , -1 , sizeof(t));

int cut(int n , int a , int b , int c)
{
    if(n==0) return 0;
    if(n<0) return INT_MIN;
    if(t[n]!=-1) return t[n];

    return t[n] = 1 + max( cut(n-a,a,b,c) , max(cut(n-b,a,b,c),cut(n-c,a,b,c)) );
}
*/



//DP - topdown
int t[10000];
void *adrs = memset(t, -1, sizeof(t));

int cut(int n, int a, int b, int c) {

    t[0] = 0;

    for(int i = 1; i <= n; i++) {


        int x = INT_MIN,
        y = INT_MIN,
        z = INT_MIN;

        if(i >= a)
        x = t[i-a];
        if(i >= b)
        y = t[i-b];
        if(i >= c)
        z = t[i-c];

        t[i] = 1 + max(x, max(y, z));
    }

    return t[n];
}


void solve() {
    int n;
    cin>>n;

    int a,
    b,
    c;
    cin>>a>>b>>c;

    cout<<cut(n, a, b, c);

    return;
}

/*****************************MAIN*************************************/
int main() {
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
    t = 1;
    //cin>>t;
    while(t-->0) {
        solve();
    }
    return 0;
}