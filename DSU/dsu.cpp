#include<iostream>
#include<vector>
#include<set>

using namespace std;

/*----------------------------------------DSU IMPLEMENTATION---------------------------*/

int Find(int edge,vector<int> &ids)
{
	if (ids[edge]!=edge) ids[edge]=Find(ids[edge],ids);
	return ids[edge];
}

void Union(int edge1,int edge2,vector<int> &ids)
{
	int parent1=Find(edge1,ids);
	int parent2=Find(edge2,ids);
	ids[parent1]=parent2;
}

/*------------------------------------------Find Components-------------------------------*/

int findComponents(int n,vector<vector<int>> edges)
{
	//Create initial array
	vector<int> ids;

	//Push all nodes
	for(int i=0;i<n;i++) ids.push_back(i);

	//Union
	for(vector<int> edge : edges){
		Union(edge[0],edge[1],ids);
	}

	//Path Compression
	set<int> s;
	set<int>::iterator st;

	for(int i=0;i<n;i++) s.insert(Find(i,ids));
	for(int i=0;i<n;i++) cout<<i<<" ";
	cout<<"\n";

	for(int i=0;i<n;i++) if(i==Find(i,ids)) {cout<<i<<" ";}
	cout<<"\n";

	return s.size();
}

/*------------------------------------------Detect Cycle--------------------------------------*/

int isCycle(int n,vector<vector<int>> edges)
{
	//Create initial array
	vector<int> ids;

	//Push all nodes
	for(int i=0;i<n;i++) ids.push_back(i);

	//Traverse each edge
	for(vector<int> edge : edges)
	{
		int x=Find(edge[0],ids);
		int y=Find(edge[1],ids);

		//Same set ,cycle is found
		if(x==y) return 1;
		Union(edge[0],edge[1],ids);
	}
	return 0;

}

/*-------------------------------------------------MAIN---------------------------------------------*/

int main()
{
	if(isCycle(6,{{0,3},{1,5},{2,1},{3,0},{4,4},{5,2}}))
        cout<<"Yes!Cycle Present";
    else
        cout<<"No!!Cycle Not Present";

	cout<<"\n";

	cout<<"No. of components: "<<findComponents(6,{{0,3},{1,5},{2,1},{3,0},{4,4},{5,2}});

	return 0;
}
