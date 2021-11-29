
/*****************************HEADERS***********************************/

#include<bits/stdc++.h>

/****************************#DEFINE************************************/

#define ll              long long
#define ull             unsigned long long
#define endl            "\n"
#define cout(x)         cout<<x<<endl
#define coutt(x,y)      cout<<x<<" "<<y<<endl
#define cin(x)          cin>>x
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
/*
vi add_two_vectors(vi c1,vi c2)
{
    int i;
    vi res(max(c1.size(),c2.size()));
    FOR(i,res.size())
    {
    if(c1.size()>i && c2.size()>i)
        res[i]=c1[i]+c2[i];

    else if(c1.size()<c2.size())
        res[i]+=c2[i];

    else if(c2.size()<c1.size())
        res[i]+=c1[i];
}*/

/*****************************SOLVE HERE*******************************/

void solve()
{
    ll int  n;
    int i,count3=0,cnt1=0,cnt2=0;
    int MIN,rem1,rem2,r1,r2,ans;

    cin(n);
    vi v(n);
    vinput(v);

    /* Any number%3 whose rem 1 or 2.
    Then sum of those two number is div by 3
    So given array can be divided into cnt1 & cnt2 */

    FOR(i,n)
    {
        if(v[i]%3==0)
            count3+=1;
        if(v[i]%3==1)
            cnt1+=1;
        if(v[i]%3==2)
            cnt2+=1;
    }

    /*min elements in the divided array means
    that much numbers can be made that sre div by 3*/

    MIN=min(cnt1,cnt2);

    /*Calculate the remaining no. of elements*/

    rem1=cnt1-MIN;
    rem2=cnt2-MIN;

    /*max no. of remaining elements that can be
    added to make sum div by 3*/

    r1=rem1/3;
    r2=rem2/3;

    ans=count3+MIN+r1+r2;
    cout(ans);
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
	cin(t);
	while(t-->0)
	{
		solve();
	}
	return 0;
}

/*********************************NOTE************************************/

/*
->Can be solved by dividing the array then summing up no.s from min length array to max length array.
    ->i.e Divide and Conquer

->But our main intention was to get the count rather than focusing on the array.

->Try to observe the pattern or some relation btw the size of the arrays while dividing.There will be some logic.

*/

/*********************************NOTE************************************/
