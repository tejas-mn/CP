/*

You are given an array of n integers, and your task is to find four values (at distinct positions) whose sum is x.

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

void solve() {
    int n, target;
    cin >> n >> target;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    // Map to store sums of pairs and their indices
    map<int, vector<pair<int, int>>> sum_map;

    // Store all pairs in the map
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = v[i] + v[j];
            sum_map[sum].emplace_back(i, j); // Store pairs with the sum
        }
    }

    // Check for two pairs whose sums add up to the target
    for (const auto& [sum, pairs] : sum_map) {
        int complement = target - sum;

        // If the complement exists in the map
        if (sum_map.find(complement) != sum_map.end()) {
            for (const auto& p1 : pairs) {
                for (const auto& p2 : sum_map[complement]) {
                    int i1 = p1.first, j1 = p1.second;
                    int i2 = p2.first, j2 = p2.second;

                    // Ensure all indices are distinct
                    if (i1 != i2 && i1 != j2 && j1 != i2 && j1 != j2) {
                        cout << i1 + 1 << " " << j1 + 1 << " " << i2 + 1 << " " << j2 + 1 << endl;
                        return;
                    }
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
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
