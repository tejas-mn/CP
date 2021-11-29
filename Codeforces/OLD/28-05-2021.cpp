
/*
 Problem-B. Petya and Staircases
 Contest-362 B
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

    ll n,m;

    int c=0;

    cinn(n,m);

    vi d(m);

    /*No dirty stairs*/
    if(m==0)
    {
        cout("YES");
        return;
    }

    for(int i=0;i<m;i++)
    {
        cin>>d[i];
    }

    /*sorting to find three consecutive elements any where in the array*/

    sort(d);

    /*if the first or the last stair is dirty,
    then Petya cannot choose a path with clean steps only*/

    if(d[0]==1 || d[m-1]==n)
    {
        cout("NO");
        return;
    }

    /*Traverse the input array to find if there are three consecutive elements*/

    for(int i=1;i<m;i++)
    {

        /*he can either jump to the next one or jump over one or two stairs at a time*/
        /*So if there are three consecutive dirty stairs he fails*/

        if(d[i]==d[i-1]+1 )
        {
            c+=1;
        }

        /*Took 1 hour just to figure out this :( */
        /*Above part should be executed 2 times in a row bcoz it should be consecutive*/
        /*Else just reset c to 0 , c=2 means there are three consecutive dirty stairs hence "NO"*/
        /*If you wanted to find 4 consecutive elements then c would be 3 ,if 5 then c would be 4 and so on..*/
        else
        {
            c=0;
        }

        if(c==2)
        {
            break;
        }

    }

    if(c==2)
    {
        cout("NO");
    }

    else
    {
        cout("YES");
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

/*Patience*/

/*********************************NOTE************************************/
