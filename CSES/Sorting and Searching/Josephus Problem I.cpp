/*
Consider a game where there are n children (numbered 1,2,\dots,n) in a circle. 
During the game, every other child is removed from the circle until there are no children left. 
In which order will the children be removed?
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

void solve() {
    int n;
    cin >> n;

    list<int> dq;

    for (int i = 0; i < n; i++) dq.push_back(i+1);

    vector<int> ans;
    int i = 1;

    while(dq.size())
    {
        int f = *dq.begin();
        dq.pop_front();
        
        if(i&1){
            dq.push_back(f);
        }else{
            ans.push_back(f);
        }

        i++;
    }

    for(auto x : ans){
        cout<<x<<" ";
    }
    
    return;
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
