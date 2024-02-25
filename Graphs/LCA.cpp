#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> g[N];
vector<int> par(N);

void dfs(int vertex , int p=-1)
{
	par[vertex] = p;
	for(int child : g[vertex]){
		if(child==p) continue;
		dfs(child  , vertex);
	}

}


vector<int> path(int v)
{
	vector<int> ans;
	while(v!=-1){
		ans.push_back(v);
		v = par[v];
	}
	reverse(ans.begin() , ans.end());
	return ans;
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
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(0);

	int x,y;
	cin>>x>>y;

	vector<int> x_path = path(x);
	vector<int> y_path = path(y);

	int min_sz = min(x_path.size() , y_path.size());
	int lca = -1;

	for(int i=0;i<min_sz;i++){
		if(x_path[i]==y_path[i]){
			lca = x_path[i];
		}
		else{
			break;
		}
	}

	cout<<lca<<endl;
	return 0;
}
