#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define endl            "\n"
#define vi              vector<int>
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define count(v,n)      count(all(v), n)
#define FOR(i,a,b)      for(int i=a;i<b;i++)
#define minv(v)         *min_element(all(v))
#define maxv(v)         *max_element(all(v))
#define FAST_IO         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int inf           =1e9 + 10;
const unsigned int M    =1000000007;
const int mod           =1e9+7;
const int INF           =0x3f3f3f3f;
const ll llINF          =9223372036854775807;
const int N             =2e5+10;


/*************************Vector-I/0 Templates*******************************/
template<typename T>
istream& operator >>(istream& istream, vector<T>& v) {
  for(auto& element : v) {
    cin >> element;
  }
  return istream;
}

template<typename T>
ostream& operator <<(ostream& ostream, vector<T>& v) {
  for(auto& element : v) {
    cout << element << " ";
  }
  return ostream;
}

template<typename T>
istream &operator >>(istream &istream, vector<vector<T>> &v){
  for(auto &row : v) {
    for(auto &cell : row) {
      cin >> cell;
    }
  }
  return istream;
}

template<typename T>
ostream& operator <<(ostream& ostream, vector<vector<T>>& v) {
  for(auto& row : v) {
    for(auto& cell : row) {
      cout << cell << " ";
    }
    cout << "\n";
  }
  return ostream;
}

/*****************************SOLVE HERE*******************************/


vi g[N];
int color[N];

bool BipartiteDFS(int v){
	for(auto u : g[v]){
		if(color[u]==-1){
			color[u] = 1-color[v];
			if(!BipartiteDFS(u)) return false;	
		}else if(color[u]==color[v]){
			return false;
		}
		
	}
	return true;
}

bool isBipartite(int n){
	memset(color , -1 , sizeof color);
	FOR(i,1,n+1){
		if(color[i]==-1){
			color[i] = 1;
			if(!BipartiteDFS(i)) return false;
		}

	}
	
	return true;
}

//Each edge with unique vertex must go into exactly one of the two sets.
void solve()
{
	int n;
	cin>>n;
	
	FOR(i,1,n+1){
		g[i].clear();
	}
	
	FOR(i,0,n){
		int a,b; cin>>a>>b;
		
		g[a].pb(b);
		g[b].pb(a);
	
	}
	
	//If in-degree > 2
	FOR(i,1,n+1){
		if(g[i].size()!=2){
				cout<<"NO"<<endl;
				 return;
		}
	}
	
	
	if(isBipartite(n)){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
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
    //t=1;
    cin>>t;
    while(t-->0){
        solve();
    }
    return 0;
}
