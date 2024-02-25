#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];
bool vis[N];
map<int, vector<int>> num_ind;
 vector<vector<int>> mp(100);
//O(V+E)
void dfs(int vertex){

    /*Take action on vertex after entering the vertex*/

    cout<<vertex<<endl;
    vis[vertex] = true;

    for(int child : g[vertex]){

       cout<<"Par : "<<vertex<<" Child : "<<child<<endl;
       // num_ind[child] = vector<int>();
      //  num_ind[child].push_back(vertex);
        mp[child].push_back(vertex);
        /*Take action on child Before exploring child*/

        if(vis[child]) continue;

        dfs(child);

        /*Take action on child After exploring child*/
    }

    /*Take action on vertex before exiting the vertex*/
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
        g[v1].push_back(v2);
        //g[v2].push_back(v1);
    }

    for(int i=0;i<m;i++){

    dfs(i);

    }

    for(auto &vec : mp){
            for(auto x : vec){
        vec.emplace_back(mp[x]);}
    }




    return 0;
}
