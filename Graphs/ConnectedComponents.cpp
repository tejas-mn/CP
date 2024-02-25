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

//to hold all connected components
vector<vi> cc;

//to store single component
vi curr_cc;

void dfs(int u) {

    vis[u] = true;

    //push back vertex of component
    curr_cc.pb(u);

    for (int v : g[u]) {
        if (vis[v]) continue;
        dfs(v);
    }
}

void mat_to_graph(vector<vector<int>> &mat)
{
    int n = mat.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
            if(i!=j && mat[i][j]==1){
                g[i].push_back(j);
            }
        }
    }
}

void solve()
{
    
    int n,e;
    cin>>n>>e;

    for(int i=0;i<e;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }

    // int n; cin>>n;
    // vector<vector<int>> arr(n , vector<int>(n,0));
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cin>>arr[i][j];
    //     }
    // }
    // mat_to_graph(arr);

    int cnt=0;

    //Call dfs on all 'n' vertices
    for (int i = 0; i <n; i++) {

        //if vertex is visited continue
        if (vis[i]) continue;

        //clear the current component vector
        curr_cc.clear();

        //call dfs on ith vertex
        dfs(i);

        //pushback the current component populated in dfs() into connected components vector
        cc.pb(curr_cc);

        //increment cc count
        cnt++;
    }

    //No. of connected components
    cout<<cc.size()<<endl;

    
    //For each component x
    for(auto x : cc){

        //for each vertex y in component x
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    

    return;
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
