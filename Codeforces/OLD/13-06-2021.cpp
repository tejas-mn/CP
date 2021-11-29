
/*
 Problem-C. Little Alawn's Puzzle
 Contest-Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)
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
#define vinput(x)       for(ull &e:x){cin(e);}
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

//Finds the parent node i.e if ids[edge]==edge
inline ull Find(ull edge,vi &ids)
{
        if(ids[edge]!= edge){
            ids[edge]= Find(ids[edge],ids);
        }
        return ids[edge];
}

//Connecting edges
inline void Union(ull edge1,ull edge2,vi &ids)
{
        ull parent1=Find(edge1,ids);
        ull parent2=Find(edge2,ids);
        ids[parent1]=parent2;
}

//Count the no. of components
inline ull countComponents(ull n, vector<vector<ull>> edges){

        //Creating the initial array of nodes
        vi ids;

        //All nodes points to themselves so ids[i]=i
        for(ull i=0;i<n;i++)
            ids.pb(i);

        //Finding union of all edges or Merging
        for(vector<ull> edge:edges )
            Union(edge[0],edge[1],ids);

        //Path Compression or Collapse and Find
        set<ull> unique_parents;
        for(ull i=0;i<ids.size()%M;i++)
                unique_parents.insert(Find(i,ids));

        return (ull)unique_parents.size();
}

void solve()
{
    ll n;
    cin(n);
    vector<ull> v1(n);
    vector<ull> v2(n);
    vinput(v1);
    vinput(v2);
    vector<vector<ull>> v3(n);
    for(ll i=0;i<n;i++)
        v3[i]={v1[i]-1,v2[i]-1};
    //cout((ll)pow(2,countComponents(n,v3))%mod);
    cout((ull int)pow(2,countComponents(n,v3))%M);
    /*
    ll ans=1;
    for(ll i=0;i<countComponents(n,v3)%mod;i++)
    {
        ans*=2;
    }
    cout(ans%mod);
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
    ll t;
    //t=1;
    cin>>t;
    while(t-->0)
    {
        solve();
    }
    return 0;
}

/*********************************NOTE************************************/

/*
Learned about implementing DSU
and got to know about passing vectors to functions using &
*/

/*********************************NOTE************************************/
