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


int longest_increasing_continious_subsequence(vector<int> &arr , int n)
{

    if(n<=1) return n;

    int cnt=1;
    int ans = 1;

    for(int i=0;i<n-1;i++)
    {
        if(arr[i]<=arr[i+1]){
            cnt+=1;
            ans = max(ans , cnt);
        }
        else{
            cnt=1;
        }
    }

    return ans;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.pb(x);
    }
    cout<<longest_increasing_continious_subsequence(arr,n);
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
