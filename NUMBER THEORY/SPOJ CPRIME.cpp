#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define endl            "\n"
#define cout(x)         cout<<x<<endl
#define cin(x)          cin>>x
#define cinn(x,y)       cin>>x>>y
#define coutt(x,y)      cout<<x<<" "<<y
#define vi              vector<int>
#define vinput(x)       for(int &e:x){cin(e);}
#define voutput(x)      for(int e:x){cout<<e<<" ";} cout<<endl;
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sort(v)         sort(all(v))
#define reverse(v)      reverse(all(v))
#define acc(v,s)        accumulate(all(v),s)
#define count(v,n)      count(all(v), n)
#define FOR(a,b)        for(int i=a;i<=b;i++)
#define minv(v)         *min_element(all(v))
#define maxv(v)         *max_element(all(v))
#define FAST_IO         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

/**************************CONSTANTS***********************************/

const int inf           =1e9 + 10;
const unsigned int M    =1000000007;
const int mod           =1e9+7;
const int INF           =0x3f3f3f3f;
const ll llINF          =9223372036854775807;
const int N             =1e5+10;
const double pi         =acos(-1.0);

/***************************COMMON FUNCTIONS***************************/

vi primes;
ll cnt=0;
void Sieve(int Max)
{
    vi ar(Max+1,1);
    ar[0]=ar[1]=0;

    for(int i=2;i<=Max;i++)
    if(ar[i]==1)
    {
        for(int j = 2*i;j<=Max;j+=i)
            ar[j]=0;
    }

    for(int i=0;i<=Max;i++)
        if(ar[i]==1)
            primes.pb(i);
}

void SegmentedSieve(int L, int R)
{
    int Max=R-L;
    vi ar(Max,1);

    if(L<=1) L++;

    for(auto p : primes)
    if(p*p<=R)
    {
        int sm = (L/p)*p;
        if(sm<L) sm+=p;

        for(int i=sm;i<=R;i+=p)
        {
            if(i!=p)
                ar[i-L]=0;
        }
    }

    FOR(0,Max)
        if(ar[i]==1)
            cnt+=1;
}

void solve()
{
    ll n;
    Sieve(100000000);

    while(cin>>n && n!=0)
    {
        SegmentedSieve(0,n);
        ll a=cnt;

        double b=(double)n/(double)log(n);

        b = abs(a-b);

        double ans=(double)(b*100)/(double)a;

        cout<<fixed<<setprecision(1);
        cout<<ans<<endl;
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

    solve();
    return 0;
}
