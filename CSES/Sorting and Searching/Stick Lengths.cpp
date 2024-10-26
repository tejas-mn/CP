/*

Given n numbers
Find min total cost to make all of them equal.
You can either lengthen and shorten each stick. Both operations cost x where x is the difference between the new and original length.

Sol: We need to choose some number that gives abs diff b/w the elements to be near for all the elements. 
In the array if we sort and observe. We see if we make all elements equal to middle number / median then it gives min cost.
because it would give differences near from both left and right side of the median ele.
*/

#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define endl            "\n"
#define vi              vector<int>
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define FOR(a,b)        for(int i=a;i<=b;i++)
#define minv(v)         *min_element(all(v))
#define maxv(v)         *max_element(all(v))
#define FAST_IO         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define DEBUG(x)        cout<<x<<endl
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
    vector<ll> v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    sort(all(v));

    ll ans = 0;

    if(n&1){
        int mid = n/2;
        for(int i=0;i<n;i++) ans+=abs(v[mid] - v[i]); 
    }else{
        int mid = n/2;
        int avg = (v[mid] + v[mid-1])/2;
        for(int i=0;i<n;i++) ans+=abs(avg - v[i]);
    }

    DEBUG(ans);
    
    return ;
}

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
