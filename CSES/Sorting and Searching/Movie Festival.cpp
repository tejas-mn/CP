/*
Given {start, end} of n movies
What is the maximum number of movies you can watch

Sol: To watch max number of movies I need to watch movies that end sooner and no overlap
So Sort according to ending times and count non overlapping intervals

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
    vector<pair<int,int>> vp(n);

    int ans = 1;

    for(int i=0;i<n;i++)
    {
        int s,e; 
        cin>>s>>e;
        vp[i].first = s;
        vp[i].second = e;
    }

    sort(all(vp), [](auto p1, auto p2){
        return p1.second < p2.second;
    });

    int end = vp[0].second;

    for(int i=1;i<n;i++)
    {
        if(vp[i].first >= end){
            end = vp[i].second;
            ans++;
        }
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
