#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> g[N];
vector<int> depth(N);


void dfs(int vertex , int par=-1)
{
	for(int child : g[vertex]){
		if(child==par) continue;
		depth[child] = depth[vertex] + 1;

		dfs(child , vertex);

	}

}

int main()
{

    /****************************STDIN/STDOUT******************************/
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    /****************************STDIN/STDOUT******************************/

	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);

	}

	dfs(1);

	int max_depth = -1;
	int max_d_node;

	for(int i=1;i<=n;i++)
	{
		if(depth[i]>max_depth){
			max_depth=depth[i];
			max_d_node=i;
		}
		depth[i]=0;
	}

	dfs(max_d_node);

	for(int i=1;i<=n;i++){
		if(depth[i]>max_depth) max_depth = depth[i];
	}

	cout<<max_depth<<endl;

	return 0;
}
