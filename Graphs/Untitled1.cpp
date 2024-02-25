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

void dfs(int u , int m, int cnt , vi &arr) {


    vis[u] = true;


    for (int v : g[u]) {


        if (vis[v]) continue;

        //count of consecutive cats
        int cons_cnt=cnt;

        //if child node and parent node have cats
        if(arr[v]==1 and arr[u]==1)
            cons_cnt+=1;
        //if only child node has cat
        else if(arr[v])
            cons_cnt=1;
        else
            cons_cnt=0;

        //more than m consecutive vertices with cats
        if(cons_cnt>m) continue;

        dfs(v , m  , cons_cnt , arr );

    }


}


void solve()
{
    int n,m;
    cin>>n>>m;

    vi v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        g[x].pb(y);
        g[y].pb(x);
    }


    int cnt=0;

    //if root node already has cat
    if(v[0]==1) cnt=1;



    dfs( 0 , m , cnt , v);

    int ans=0;

    for(int i=0;i<n;i++)
    {
        //restrnt visited and g[i].size()==1 -> check for leaf node and i!=0 (not root node)
        if(vis[i] and g[i].size()==1 and i!=0)
        {
            ans++;
        }
    }

    cout<<ans<<endl;


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

