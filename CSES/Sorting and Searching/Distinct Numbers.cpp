/*
Find distinct number of values in the list
Sol: 
1. Use set 
2. Sort and Skip duplicates by skipping adjacent eq elements and pointing always to a distinct value

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
    set<int> s;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        s.insert(x);
    }
    cout<<s.size()<<endl;
    return ;
}

void solve1(){
    int n; 
    cin>>n; 
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int ans  = 0;
    sort(all(v));

    int j = 0;

    while(j<n){
        ans++;
        j++;

        while(j > 0 && v[j] == v[j-1]) j++;
    }

    cout<<ans<<endl;
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
        solve1();
    }
    return 0;
}
