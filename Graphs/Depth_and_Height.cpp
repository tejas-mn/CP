#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

vector<int> g[N];
vector<int> depth(N) , height(N);

void dfs(int vertex , int par=-1)
{
	for(int child : g[vertex]){
		if(child==par) continue;

		depth[child] = depth[vertex] + 1;

		dfs(child , vertex);

		height[vertex] = max(height[vertex] , height[child]+1);
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
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1);

	for(int i=1;i<=n;i++)
	{
		cout<<depth[i]<<" "<<height[i]<<endl;
	}

	return 0;
}
