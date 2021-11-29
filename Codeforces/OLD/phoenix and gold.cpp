
/*
 Problem-Phoenix and gold
 Contest-1515A
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

/*****************************SOLVE HERE*******************************/

void solve()
{
    ll n,k,i=0;
    cinn(n,k);
    vi v(n);
    vinput(v);
    int temp;
    int sum=0;


    FOR(i,n)
    {
        sum=sum+v[i];
    }

    /*Handles single element case automatically*/
    /*i.e (sum==k and i=0) */

    if(sum==k)
    {
        cout("NO");
        return;
    }

    /*There exists a solution*/

    else

    {
        cout("YES");
        FOR(i,n)
        {
            if(v[i]==k)
            {
                temp=v[i];
                v[i]=v[i+1];
                v[i+1]=temp;
            }

            cout<<v[i]<<" ";

            /*Decrement k each time u add new weight.*/
            /*To check if adding next weight in the loop makes it to explode*/
            //Eg- if k=3 and v=3,2,1
            //v->2 3 1 and k=3-2=1
            //so next time when i add 1 it will explode bcoz 2+1==3
            //But nxt element would be 3!=1 & k=1-3=-2 lastly 1!=-2 && k=-2-1=-3

            k=k-v[i];
        }
        cout(endl);
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
    //t=1;
    cin>>t;
    while(t-->0)
    {
        solve();
    }
    return 0;
}

/*********************************NOTE************************************/

/**/

/*********************************NOTE************************************/
