#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define endl            "\n"
#define vi              vector<int>
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define count(v,n)      count(all(v), n)
#define FOR(a,b)        for(int i=a;i<=b;i++)
#define minv(v)         *min_element(all(v))
#define maxv(v)         *max_element(all(v))
#define FAST_IO         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int inf           =1e9 + 10;
const unsigned int M    =1000000007;
const int mod           =1e9+7;
const int INF           =0x3f3f3f3f;
const ll llINF          =9223372036854775807;
const int N             =1e5+10;

/*****************************SOLVE HERE*******************************/



void solve()
{
    int h1,h2,m1,m2;
    scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);

    //convert everything to minutes
    m1 = m1+h1*60;
    m2 = m2+h2*60;

    int m3 = (m1+m2)/2;

    //fill 2 places with 0 if the 1st place is one digit rest one place is filled by 0
	cout<<setfill('0')<<setw(2)<<m3/60<<":"<<setfill('0')<<setw(2)<<m3%60<<endl;

	//printf("%02d:%02d\n", m3 / 60, m3 % 60);
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
    while(t-->0){
        solve();
    }
    return 0;
}
