#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int INF = 1e9+10;

vector<pair<int,int>> g[N];
bool vis[N];
vector<int> level(N , INF);

//O(V+E)
void bfs(int src)
{
    deque<int> q;
    q.push_back(src);
    level[src]=0;

    while(!q.empty())
    {
        int cur_v = q.front();
        q.pop_front();

        //cout<<cur_v<<" ";
        for(auto child:g[cur_v])
        {
            int v = child.first;
            int wt = child.second;

            if(level[cur_v]+wt<level[v]){
                level[v] = level[cur_v] + wt;
                if(wt==1){
                    q.push_back(v);
                }else{
                    q.push_front(v);
                }
            }
        }

    }


}

int main()
{

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        int v1,v2;
        cin>>v1>>v2;
        //ignore self loops
        if(v1==v2) continue;
        g[v1].push_back({v2,0});
        g[v2].push_back({v1,1});
    }

    bfs(1);

    (level[n]==INF)? cout<<-1 : cout<<level[n];

    //for(int i=1;i<=n;i++){
       // cout<<i<<" "<<level[i]<<endl;
    //}

    return 0;
}
