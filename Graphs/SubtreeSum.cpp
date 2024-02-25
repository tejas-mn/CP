#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> g[N];
vector<int> subtree_sum(N)  , evn_cnt(N) , val(N);


void dfs(int vertex , int par=0)
{
	if(vertex%2==0) evn_cnt[vertex]++;
	subtree_sum[vertex]+=val[vertex];

	for(int child:g[vertex])
	{
		if(child==par) continue;

		dfs(child, vertex);

		subtree_sum[vertex]+=subtree_sum[child];
		evn_cnt[vertex]+=evn_cnt[child];
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
	for(int i=1;i<=n;i++) cin>>val[i];

	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}


	dfs(1);

	for(int i=1;i<=n;i++)
	{
		cout<<subtree_sum[i]<<" "<<evn_cnt[i]<<endl;
	}

	return 0;
}
