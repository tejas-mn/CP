/*

 process the cubes in the given order
 two cubes are one on top of the other, the upper cube must be smaller than the lower cube.
 can always either place the cube on top of an existing tower, or begin a new tower
 What is the minimum possible number of towers?

*/

#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define endl            "\n"
#define vi              vector<int>
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define FOR(a,b)        for(int i=a;i<=b;i++)
#define minv(v)         *min_element(all(v))
#define maxv(v)         *max_element(all(v))
#define FAST_IO         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define DEBUG(x)        cout<<x<<endl
using namespace std;

const int inf           =1e9 + 10;
const unsigned int M    =1000000007;
const int mod           =1e9+7;
const int INF           =0x3f3f3f3f;
const ll llINF          =9223372036854775807;
const int N             =1e5+10;

/*****************************SOLVE HERE*******************************/

void solve()
{
    int n,target;
    cin>>n>>target;

    vector<int> v(n);
    
    for(int i=0;i<n;i++) cin>>v[i];

    int idx_1 = -1;
    int idx_2 = -1;
    int idx_3 = -1;

    map<int,int> mp;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1; j<n;j++){
            if(mp.count(v[i] + v[j]) > 0 && mp[v[i] + v[j]] - 1 != j && mp[v[i] + v[j]] - 1 != i ){
                idx_1 = mp[v[i] + v[j]];
                idx_2 = i+1;
                idx_3 = j+1;
                break;
            }    
        }

        mp[target - v[i]] = i+1;
    }

    if(idx_1 == -1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    
    cout<<idx_1<<" "<<idx_2<<" "<<idx_3<<endl;

    return ;
}

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
