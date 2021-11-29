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

    vi arr(n);
    for(auto &x:arr) cin>>x;

    //==>res[k] represents the kth transformed array
    vector<vi> res;

    //push initial array
    res.pb(arr);

    //==>transformation stops at some point..so loop till 100 is enough..i think..so precompute
    for(int t=0;t<100;t++){

        //store freq of elements in map
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;

        //transform the array
        for(int i=0;i<n;i++) arr[i] = mp[arr[i]];

        //store each transformation in res so that each query takes O(1) time
        res.pb(arr);
    }

    int q;
    cin>>q;

    //==>answer each query in O(1) time
    while(q-->0){
        int x,k;
        cin>>x>>k;

        if(k>100) k=100;
        cout<<res[k][x-1]<<endl;
    }

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
    //t=1;
    cin>>t;
    while(t-->0){
        solve();
    }
    return 0;
}
