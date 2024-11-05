/*

What is the longest sequence of successive songs where each song is unique in n songs

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
    int n;
    cin>>n;
    vector<int> v(n);
    map<int,int> mp;
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    int ws = INT_MIN;
    
    int i=0;
    int j=0;
    
    while(j<n){
        mp[v[j]]++;
        if(mp.size()==j-i+1){
            ws = max(ws , j-i+1);
        }
        while(mp.size() < j-i+1){
            mp[v[i]]--;
            if(mp[v[i]]==0){
                mp.erase(v[i]);
            } 
            if(mp.size()==j-i+1){
                ws = max(ws , j-i+1);
            }
            i++;
        }
        if(mp.size()==j-i+1){
            ws = max(ws , j-i+1);
        }
        j++;
    }
    
    DEBUG(ws);
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
