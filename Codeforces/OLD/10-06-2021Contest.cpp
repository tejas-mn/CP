
/*
 Problem-
 Contest-725 Div3
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
#define FOR(i,n)        for(int i=0;i<n;i++)
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

/*****************************SOLVE HERE*******************************/

void solve(int t)
{
    ll n;
    cin(n);
    vi v(n);
    vinput(v);

    ll minv=minv(v);
    ll maxv=maxv(v);

    ll min_lr;
    ll min_rl;
    ll max_lr;
    ll max_rl;

    FOR(i,n)
    {
        if(v[i]==minv)
        {
            min_lr=i+1;
        }

        if(v[i]==maxv)
        {
            max_lr=i+1;
        }

    }

/*
    ll m =max(min_lr,max_lr);

    if(max_lr==m)
    {
            max_lr=max_lr-(min_lr-1);
    }
    else
    {
        min_lr=min_lr-(max_lr-1);
    }
*/

  ll case1=  min(min_lr,max_lr)+(abs(max_lr-min_lr));


    //if(v[min_lr-1]==maxv && v[max_lr-1]==minv){
      //  swap(min_lr,max_lr);
    //}
        //max_lr=max_lr-min_lr;


    //coutt(min_lr,max_lr);

    reverse(v);

        FOR(i,n)
    {
        if(v[i]==minv)
        {
            min_rl=i+1;
        }

        if(v[i]==maxv)
        {
            max_rl=i+1;
        }

    }

/*
    ll s =max(min_rl,max_rl);

    if(max_rl==s)
    {
            max_rl=max_rl-(min_rl-1);
    }
    else
    {
        min_rl=min_rl-(max_rl-1);
    }
*/
    //coutt(min_rl,max_rl);

ll case2=  min(min_rl,max_rl)+(abs(max_rl-min_rl));
    //coutt(min_lr,max_lr);
    //coutt(min_rl,max_rl);
    //cout(min(min_lr,min_rl)+min(max_lr,max_rl));

    if(t==3){
        cout(min(case1,case2)-3);

    }else{
        cout(min(case1,case2));
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
    int t;
    //t=1;
    cin>>t;
    while(t-->0)
    {
        solve(t);
    }
    return 0;
}

/*********************************NOTE************************************/

/**/

/*********************************NOTE************************************/
