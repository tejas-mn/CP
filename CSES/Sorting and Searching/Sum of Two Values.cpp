/*

Given n numbers
Find 2 distinct positions of 2 numbers that sum to x

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
    int n, target;
    cin>>n>>target;
    vector<int> v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    map<int,int> mp;

    for(int i=0;i<n;i++)
    {
        if(mp.count(target-v[i]) > 0 && (mp[target - v[i]]-1 != i))
        {
            cout<<mp[target - v[i]]<<" "<<i+1<<endl;
            return;
        }
        mp[v[i]] = i+1;
    }
    DEBUG("IMPOSSIBLE");
    return ;
}

void solve1(){
    int n, target;
    cin>>n>>target;
    vector<int> v(n);

    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> tmp = v;
    
    sort(all(v));
    
    int l = 0;
    int r = n-1;

    int x = -1;
    int y = -1;

    while(l<r){
        if(v[l] + v[r] == target){
            x = v[l]; y = v[r];
            break;
        }else if(v[l] + v[r] > target){
            r--;
        }else{
            l++;
        }
    }
    
    if(x!=-1 && y!=-1){
        int j = -1;
        int k = -1;
        for(int i=0;i<n;i++){
            if(tmp[i] == x){
                j = i;
            }
        }
        
        for(int i=0;i<n;i++){
            if(tmp[i] == y && j!=i){
                k = i;
            }
        }

        cout<<j+1<<" "<<k+1<<endl;
        return;
    }

    DEBUG("IMPOSSIBLE");

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
        solve1();
    }
    return 0;
}
