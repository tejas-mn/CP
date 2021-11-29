
/*
 Problem-B. Gifts Fixing
 Contest-661 Div 3
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
#define vl              vector<long long>
#define vinput(x)       for(int &e:x){cin(e);}
#define vlinput(x)       for(long long &e:x){cin(e);}
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

    ll n,i,min_candies,min_oranges;
    cin(n);

    vl candies(n);
    vl oranges(n);

    vlinput(candies);
    vlinput(oranges);

    ll ans=0;


    /*Consider each array independently*/


    /*Find min(first array) to equalize the first array*/
    /*Find min(second array) to equalize the second array*/

    min_candies=minv(candies);
    min_oranges=minv(oranges);

    /*maximum moves we need for each i to decrease simultaneously*/


    FOR(i,n)
    {

        /*Simultaneously find max of these and add all of them*/
        /*This gives the minimum number of moves required to equalize all the given array.*/

        ans=ans+max(

                    /*decrease all candies[i] to the value min(candies)*/
                    candies[i]- min_candies,

                    /*decrease all oranges[i] to the value min(oranges)*/
                    oranges[i]-min_oranges

                    );
    }

    cout(ans);
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

/**/

/*********************************NOTE************************************/
