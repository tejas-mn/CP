/*
Given n children weights
And each seat can have 1 or 2 child in it
And total weight in the seat should be <= max allowed weight
Find minimum number of seats required for the childrens

Sol:
Worst case: each child single seat
But since each seat can have at max 2 children, we try to include another child. But on what basis the another child should be taken?
The goal is to occupy as much children with minimum seats
Greedily we try to include 2 childrens in a seat as much as possible But we have max allowed weight constraint

First Idea:
We can sort the childrens by weight and pair childrens with less weight from starting
But given the max allowed weight 
And we include children with smaller weights then total seat weight will also be smaller
Which gives larger diff between the max allowed weight, meaning we are wasting remaining weight 
And we are not utilizing it most effeciently

Second Idea:
Pair childrens with more weight from end
But given the max allowed weight 
And we include children with larger weights then total seat weight will also be larger which looks good
But as we approach at start then again we pair children with smaller weights which gives larger difference with max allowed weight and remaining weight gets wasted

Best case: Pairing smaller and larger weight children obeying max allowed weight. 
This way we can pair maximum number of 2 pair childrens and remaning single childrens can go in single seat 

*/

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
#define DEBUG(x)        cout<<x<<endl
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
    int n,maxWeightAllowed;
    cin>>n>>maxWeightAllowed;
    vector<int> childrenWeights(n);
    
    for(int i=0;i<n;i++) cin>>childrenWeights[i];
    sort(all(childrenWeights));

    int ans = 0;
    
    int l = 0;
    int r = n-1;

    while(l<=r)
    {
        if(l<r && childrenWeights[l] + childrenWeights[r] <= maxWeightAllowed)
        {
            l++;
            r--;
            ans++;
        }
        else{
            r--;
            ans++;
        }
    } 
    
    DEBUG(ans);

    return ;
}

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
    while(t-->0){
        solve();
    }
    return 0;
}
