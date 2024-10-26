/*
 Given the arrival and leaving times of n customers in a restaurant.
 Print one integer: the maximum number of customers.

Sol1 : pref[s]++; pref[e+1]--; then taking prefsix sum of all and taking max
Sol2: Maintain vec<pair> pushing {start, +1}, {end, -1} then sort and then take max sum over all
*/

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
    vector<pair<int,int>> pref;
    set<pair<int,int>> s;

    for(int i=0;i<n;i++){
        int s,e; 
        cin>>s>>e;
        pref.push_back({s, +1});
        pref.push_back({e, -1});
    }
    
    sort(pref.begin(), pref.end());

    int sum = 0;
    int ans = 0;

    for(auto p : pref)
    {
        sum += p.second;
        ans = max(ans, sum);
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
