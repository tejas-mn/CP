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

int MAX = 1e6+1;

vi lp(MAX,0),hp(MAX,0);
void Sieve(int Max)
{
    vi ar(Max+1,1);
    ar[0]=ar[1]=0;

    for(int i=2;i<=Max;i++)
    if(ar[i]==1)
    {
        //lowest prime and highest prime of prime is itself
        lp[i]=hp[i]=i;

        for(int j = 2*i;j<=Max;j+=i)
         {
             ar[j]=0;

             //highest prime
             hp[j]=i;

             //lowest prime
             if(lp[j]==0){
                lp[j]=i;
             }
         }
    }

    //for(int i=2;i<100;i++)
        //cout<<lp[i]<<" "<<hp[i]<<endl;
}

//Prime Factorization using Seive O(logn)
void primeFactorization(int num)
{
    vi prime_factors;
    map<int,int> pfs;

    cout<<"**PrimeFactors of "<<num<<"**"<<endl;
    while(num>1){

        //Get highest prime
        int pf = hp[num];

        //While the number is div by prime factor
        while(num%pf==0){

            //Divide the number by prime factor
            num/=pf;

            //Push the prime factor to vector
            prime_factors.pb(pf);

            //Store the count of each prime factor in map
            pfs[pf]++;
        }
    }


    for(auto factor : prime_factors)
        cout<<factor<<" ";
    cout<<endl;
}

const int N = 1e5 + 10;
vi divisors[N];

void Divisors(int num)
{

    for(int i=2;i<N;i++){
        for(int j=i;j<N;j+=i){
            divisors[j].pb(i);
        }
    }

    cout<<"**Divisors till "<<num<<"**"<<endl;
    for(int i=2;i<num;i++)
    {
        cout<<i<<"->";
        for(int div : divisors[i])
        {
            cout<<div<<" ";
        }
        cout<<endl;
    }
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

    Sieve(MAX);

    int n;
    cin>>n;

    primeFactorization(n);
    Divisors(n);
    return 0;
}
