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

const int inf           =1e9 + 10;
const unsigned int M    =1000000007;
const int mod           =1e9+7;
const int INF           =0x3f3f3f3f;
const ll llINF          =9223372036854775807;
const int N             =1e5+10;

/*****************************SOLVE HERE*******************************/

bool vis[N];
vi g[N];
vector<int> par(N);


void solve()
{
    int n,e;
    cin>>n>>e;

    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        par[x]++;
        par[y]++;
    }

    int cnt1=0;
    int cnt2=0;
    int cnt3=0;

    for(int i=1;i<=n;i++)
    {

        if(par[i]==1) cnt1++;
        else if(par[i]==2) cnt2++;
        else cnt3++;
    }


    if(cnt1==n-1 and cnt3==1){
        //center node connected to n-1 nodes => cnt1==n-1
        //all n-1 nodes have only one parent i.e center node => cnt3==1
        cout<<"star topology"<<endl;
    }
    else if(cnt2==n and e==n){
        //all nodes connected to 2 nodes
        cout<<"ring topology"<<endl;
    }
    else if(cnt1==2 and cnt2==n-2){
        //first and last node connected to only one node => cnt1==2
        //rest all connected to two nodes => cnt2==n-2
        cout<<"bus topology"<<endl;
    }
    else{
        cout<<"unknown topology"<<endl;
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
    //cin>>t;
    while(t-->0){
        solve();
    }
    return 0;
}
