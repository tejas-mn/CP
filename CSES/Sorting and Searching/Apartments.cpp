/*
Given n people and m houses and maximum allowed difference k
And each person accepts house if its size is close to their desired size
If the desired size of an applicant is x, he or she will accept any apartment whose size is between x-k and x+k.
Distribute houses so that max people get the houses

Sol: Sort + two pointers : Move both pointers if satisified else decide which pointer to move further

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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> desiredSize(n), houseSize(m);
    
    for(int i=0;i<n;i++) cin>>desiredSize[i];
    
    for(int i=0;i<m;i++) cin>>houseSize[i];
    
    sort(all(desiredSize)); sort(all(houseSize));

    int d = 0;
    int h = 0;
    int ans = 0;

    while(d < n && h < m)
    {
        //if house is satisfied move to next person and next house
        if(houseSize[h] >= desiredSize[d] - k && houseSize[h] <= desiredSize[d] + k){
            h++;
            d++;
            ans++;
        }
        //if house is bigger than the desired size, move to next person
        else if(houseSize[h] > desiredSize[d] + k){
            d++;
        }
        //if house is smaller than the desired size, move to next house
        else if(houseSize[h] < desiredSize[d] - k){
            h++;
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
