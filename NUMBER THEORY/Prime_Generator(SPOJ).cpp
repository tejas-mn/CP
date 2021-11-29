#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define endl            "\n"
#define vi              vector<int>
#define pb              push_back
#define REP(a,b)        for(int i=a;i<=b;i++)
#define FAST_IO         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


/*****************************SOLVE HERE*******************************/

vi primes;
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

    REP(0,Max)
        if(ar[i]==1)
            cout<<L+i<<endl;
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

    //Precompute Seive(approx 1e6+1) before taking testcases
    Sieve(1000000);

    int t,L,R;
    cin>>t;

    while(t-->0)
    {
        cin>>L>>R;
        SegmentedSieve(L,R);
        cout<<endl;
    }

    //for(auto x : primes) cout<<x<<endl;

    return 0;
}
