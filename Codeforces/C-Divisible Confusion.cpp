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
    vi v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];

    bool ans = true;

    //for each v[i]
    for(int i=1;i<=n;i++){

        //check if v[i] is div by i+1
        bool check = false;

        //so loop through i+1(last) to 2 so i does not change after the deletion operation
        //TC : O(n*23*n) bcoz lcm(2...23) ~ =>10^9 ==> 10^9/>10^9 then rem !=0 so loop breaks above i=23 something
        for(int j = i+1;j>1;j--){
            if(v[i]%j!=0){
                check = true;
                break;
            }
        }

        ans&=check;
    }

    ans?(cout<<"YES"<<endl):(cout<<"NO"<<endl);
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
