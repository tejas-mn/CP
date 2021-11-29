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
//TopDown
bool UnboundedSubsetSum(int arr[], int n, int sum)
{
    //dp table
    bool t[n+1][sum+1];

    //BaseCase--> Initialization of first row first column
    //(n,sum)=>(i,j)
    //n==0 and sum>0 ->false
    //n>=0 and sum==0 ->true empty subset{} gives sum 0 for any n


    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
                t[i][j] = false;
            if(j==0)
                t[i][j] = true;
        }
    }

    //ChoiceDiagram-->Recursive->Iterative

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            //if (n-1)th number is less than sum we can include or exclude
            if(arr[i-1]<=j)
                t[i][j] = (t[i][j-arr[i-1]]) or (t[i-1][j]);    /*i-1 -> i since number can be included as many times*/
            else
                t[i][j] = t[i-1][j];
        }
    }

    return t[n][sum];
}

void solve()
{
    int sum;
    cin>>sum;

    int arr[] = {2020,2021};
    if(UnboundedSubsetSum(arr, 2 , sum))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

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
    while(t-->0){
        solve();
    }
    return 0;
}
