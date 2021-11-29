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

void solve()
{
    int n;
    cin>>n;
    vi v(n);
    vi red , blue;

    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n;i++){
        char color;
        cin>>color;
        if(color=='R')
            red.pb(v[i]);
        else
            blue.pb(v[i]);
    }

    sort(red.rbegin(),red.rend());
    sort(blue.begin(),blue.end());

    bool check = true;

    for(int i=0;i<blue.size();i++)
    {
        if(blue[i]<i+1){
            check = false;
            break;
        }
    }

    for(int i=0;i<red.size();i++)
    {
        if(red[i]>n-i){
            check = false;
            break;
        }
    }

    check?(cout<<"YES"<<endl):(cout<<"NO"<<endl);

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
