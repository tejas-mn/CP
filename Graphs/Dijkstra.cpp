#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6+10;
const ll int INF = 1e11+10;

vector<pair<ll,ll>> g[N];
vector<ll> dist(N , INF);
vector<bool> vis(N , false);
vector<ll> prevv(N,-1);

void printpath(ll src){
    if(prevv[src]!=-1) printpath(prevv[src]);
    cout<<src<<" ";
}

void dijkstra(ll source){

    //pair<dist,node>
    //set sorted according to first item in pair(dist)
    //min dist node will be on top and will be removed first
    set<pair<ll,ll>> st;

    st.insert({0,source});
    dist[source] = 0;

    while(!st.empty()){
        auto node = *st.begin();

        ll u = node.second;
        ll dist_u = node.first;
       // cout<<dist_u<<" "<<u<<endl;
        st.erase(st.begin());

        //if(vis[u]) continue;
        //vis[u]=true;

        //relax all every nodes connected to u
        for(auto child : g[u])
        {
            ll v = child.first;
            ll cost_v = child.second;

            //relaxation
            if(dist_u + cost_v <dist[v]){
                prevv[v] = u;
                dist[v] = dist_u + cost_v;
                st.insert({dist[v] , v});
            }
        }
    }

}

int main(){
    /****************************STDIN/STDOUT******************************/
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    /****************************STDIN/STDOUT******************************/

    ll n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        ll x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt});
        g[y].push_back({x,wt});
    }
    int start; cin>>start;

    dijkstra(start);
    if(dist[n]!=INF)
        printpath(n);
  else
       cout<<-1<<endl;

    for(int i=1;i<=n;i++) cout<<i<<" "<<dist[i]<<endl;
    return 0;
}
