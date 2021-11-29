
/*
 Problem-Substring removal game
 Contest-1398 B
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

/*****************************SOLVE HERE*******************************/

void solve()
{
    string s;
    cin(s);

    vi v;

    int i=0;

    /*Count of size of blocks with 1's*/
    int c=0;

    /*While string is not exhausted*/

    while(s[i]!='\0')
    {

        /*If I find a one increment c*/
        if(s[i]=='1')
        {
            c+=1;
        }
        /*If I encounter a 0 I will
        pushback the count of one's and
        reset c to count next 1's */

        if(s[i]=='0')
        {
            v.pb(c);
            c=0;
        }


        i++;

    }

    /*If at last if I had encountered a 1 ,c wouldn't be pushed back in while loop */
    /*So this will pb last count of 1's*/

    if(s[s.size()-1]=='1')
        v.pb(c);

    /*Sort the vector in decreasing order*/

    sort(v);
    reverse(v);

    cout("No. of 1's present in group/block or substring: ");
    voutput(v);

    cout("Maximum 1's in a block: ");
    cout(v[0]);

    /*Add elements at even position(Alice 1's)*/
    int ans=0;
    FOR(i,v.size())
    {
        if(i%2==0)
            ans=ans+v[i];
    }

    cout("Alice's score: ");
    cout(ans);
    cout("\n");
    return;
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

/*Basically Given a string count no. of 1's present in a group/block/substring*/

/*********************************NOTE************************************/
