/*

Given n numbers
print the smallest sum that cannot be obtained from the subsets 

Sol: 
Brute - iterate from 1 to total sum and checking if it is possible or not using subset sum dp approach but gives tle
Observation - 
They are asking for minimum sum. Min sum that can be made is min ele. The next min sum would be summing the min elements..
So Lets sort the array and observe. Since we need minimum we start observing from left min ele..
Lets say we have traversed array from index 0 to some i. Then we need to check all the subset sums that are possible from the array till i to find the min sum not possible.
But instead of finding all the subsets. Since array is sorted we can look at all the subarray sums left of i. 
But is it necessary to look all the sums? Observe how sum is formed induvidually by extending next element.
We can always extend the new element that is coming next and include that ele it in whatever subsets is formed till that element
Similarly here we need to look for what is the next sum that can be generated or not.

As we move left we can compute prefix sum. And this pref sum + 1 should be greater than coins[i].
If its less than coins[i]. It means there is some gap between the pref sum and coins[i] and pref sum + 1 cannot be formed 

*/

#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define endl            "\n"
#define vi              vector<int>
#define pb              push_back
#define all(v)          v.begin(),v.end()
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
    int n;
    cin>>n;
    vector<ll> v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    sort(all(v));

    ll sum = 0;

    for(int i=0;i<n;i++)
    {
        if(sum + 1 < v[i]) //cgecking if next sum is less than coins[i]
        {
            break;
        }
        sum+=v[i];
    }

    DEBUG(sum + 1);
    
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
