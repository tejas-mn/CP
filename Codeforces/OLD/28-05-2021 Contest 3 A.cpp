
/*
 Problem-
 Contest-723
*/

/*****************************HEADERS***********************************/

#include<bits/stdc++.h>

/****************************#DEFINE************************************/

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
#define FOR(i,n)        for(i=0;i<n;i++)
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

ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
bool iseven(int n) {return (n%2==0)?true:false;}
void swap(int *a,int *b){ int temp=*a;*a=*b;*b=temp;}

int primes[100001];

void sieveOfEratosthenes(int N) {

   N+=2;
   primes[1] = 1;
   for (int i=2; i<N; i++)
      primes[i] = i;
   for (int i=4; i<N; i+=2)
      primes[i] = 2;
   for (int i=3; i*i<N; i++) {
      if (primes[i] == i) {
         for (int j=i*i; j<N; j+=i)
            if (primes[j]==j)
               primes[j] = i;
      }
   }
}

vi temp;

void findPrimeFactors(int num) {

   sieveOfEratosthenes(num);
   int factor;
   while (num != 1) {
      factor = primes[num];
      //cout<<factor<<" ";
      temp.pb(-1*factor);
      num /= factor;
   }
}

/*****************************SOLVE HERE*******************************/

void solve()
{
    ll n;
    ll sume=0;
    ll sumn=0;
    int i;
    cin(n);
    vi v(n);
    vinput(v);
    sort(v);
    FOR(i,n)
    {
        if(v[i]<0){
        sumn=sumn+v[i];
        }
        if(v[i]>=0)
        {
            sume=sume+v[i];
        }
    }
    std::vector<int>::iterator it;
    it = find (all(v),(sume+sumn));
    int ans=sume+sumn;
    if (it != v.end())
    {
        ans=n-1;
        cout(ans);
        return;
    }
    else
    {
        findPrimeFactors(-1*ans);
    std::vector<int>::iterator  ls;
    sort(temp);
    ls = std::set_intersection(all(v),all(temp), v.begin());
    int cc=ls - v.begin();
    if(cc!=0)
    {
        cout(n-cc);
        return;
    }
    }
    if(sume+sumn==0)
    {
        cout(n);
        return;
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
    int t;
    t=1;
    //cin>>t;
    while(t-->0)
    {
        solve();
    }
    return 0;
}

/*********************************NOTE************************************/

/**/

/*********************************NOTE************************************/
