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


/*****************************SOLVE HERE*******************************/

const int N  = 1e3+10;
int graph1[N][N];
vector<pair<int,int>> graph2[N];

void solve()
{
    //n-vertex , m-edges
    int n,m;

    for(int i=0;i<n;i++){
        int v1,v2,wt;
        cin>>v1>>v2>>wt;

        //Adjacency Matrix - O(N^2) N<=10^3
        graph1[v1][v2]=wt;
        graph1[v2][v1]=wt;

        //Adjacency List - O(N+M)
        graph2[v1].pb({v2 , wt});
        graph2[v2].pb({v1 , wt});

    }

    //i,j connected?
    if(graph1[i][j]==1){}

    for(auto child : graph2[i]){
        if(child==j){
            //connected
        }
    }

    return ;
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
