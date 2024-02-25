#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];
bool vis[N];
vector<int> level(N);

//O(V+E)
void bfs(int src)
{
    queue<int> q;

    q.push(src);
    vis[src] = true;

    while(!q.empty())
    {
        int cur_v = q.front();
        q.pop();

        cout<<cur_v<<" ";
        for(auto child:g[cur_v])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[cur_v] + 1;
            }
        }

    }
    cout<<endl;

}

int main()
{

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    bfs(1);

    for(int i=1;i<=n;i++){
        cout<<i<<" "<<level[i]<<endl;
    }

    return 0;
}
