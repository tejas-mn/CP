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


int binexp(int a, int b, int m){

  int ans=1;

  while(b){

    if(b&1){
      ans = (ans * 1LL * a)%m;
    }

    a = (a*1LL*a)%m;

    b>>=1;
  }

  return ans;

}

void solve()
{
    ll n,k;
    cin>>n>>k;


    //Using Binexp--O(logn)
    ll sum = 0 , i = 0;
    while(k){

      if(k&1){
        sum = (sum + (binexp(n,i,M))%M)%M;
      }

      k>>=1;
      i++;
    }

    cout << sum << endl;



    /*
    //Using Bitmasks
    ll p = 1 , ans = 0;

    //Traverse through the bits of k--O(number of bits in k)
    FOR(0,31)
    {
        //If the ith bit is set compute ans by adding p (n^required power(i.e set bit position in k))
        if(k & (1<<i)){
            ans = (ans + p) % M;
        }

        //compute power of base n
        p *= n;
        p %= M;
    }
    cout<<ans<<endl;
    */

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
