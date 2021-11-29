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


vi ar(10000000,1);
vi steps(10000000,0);
void Sieve()
{

    ar[0]=ar[1]=0;

    for(int i=2;i<=10000000;i++)
    if(ar[i]==1)
    {
        for(int j = 2*i;j<=10000000;j+=i)
            ar[j]=0;
    }
    for(int i=2;i<=10000000;i++)
        steps[i] = steps[i-1] + ar[i];


}

/*
bool isPrime(ll n)
{
    if(n==1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;

    for(int i=5;i*i<=n;i=i+6)
    {
        if(n%i==0 || n%(i+2)==0)
            return false;
    }
    return true;
}
*/


void solve()
{
    int x,y;
    cin>>x>>y;



    int jump = y -x;
    jump  = jump - (steps[y] - steps[x]);
    (ar[x+1])?cout<<jump+1<<endl : cout<<jump<<endl;

    return ;

}

/*****************************MAIN*************************************/
int main()
{

    FAST_IO;

    Sieve();
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
