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

int no_of_cards[40000];

//precompute no_of_cards req for height h
void precompute()
{

    no_of_cards[0]=0;
    no_of_cards[1]=2;

    for(int h=2;h<4*1e4;h++)
    {
        //no_of_cards req for height h = no_of_cards[h-1] + total base [(2*h->base + to cover top of base(h-1))]
        no_of_cards[h] = no_of_cards[h-1] + (2*h + h-1);
    }
}

int binarySearch(int n , int low , int high)
{

    while(low<high)
    {
        int mid = (low+high)/2;

        if(n==no_of_cards[mid])
            return mid;
        else if(n<no_of_cards[mid])
            high=mid-1;
        else
            low=mid+1;
    }

    if(n>=no_of_cards[low]) return low;

    return low-1;
}

void solve()
{
    int n;
    cin>>n;

    int cnt=0;

    while(n>1)
    {
        int max_height = binarySearch(n , 0 , 4*1e4);
        cnt++;
        n-= no_of_cards[max_height];
    }

    cout<<cnt<<endl;
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
    precompute();
    int t;
    //t=1;
    cin>>t;
    while(t-->0){
        solve();
    }
    return 0;
}
