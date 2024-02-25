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

bool vis[N];
vi g[N];

void ginput(int n, int e){
    for(int i=0;i<e;i++){
        int v1,v2; cin>>v1>>v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
}

bool dfs(int u , int par) {
    vis[u] = true;
    bool isloop = false;
    for (int v : g[u]) {
        if(vis[v] and v==par) continue;
        if (vis[v]) return true;
        isloop |= dfs(v , u);
    }
    return isloop;
}


bool isCycle(int n , int &cnt)
{
    bool found = false;

    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(dfs(i,0)){
            found = true;
            cnt++;
        }
    }

    return found;
}

void solve()
{
    int n,e;
    cin>>n>>e;

    ginput(n,e);
    int cnt=0;
    isCycle(n , cnt);
    cout<<cnt<<endl;

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
    while(t-->0){
        solve();
    }
    return 0;
}
