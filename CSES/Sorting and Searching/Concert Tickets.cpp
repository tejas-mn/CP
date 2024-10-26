/*
Given n ticket prices
And m customers
Each customer announce max price willing to pay for the ticket
Then they will get the ticket with nearest price without exceeding the max price
Given above for each customer
Print the price they will pay to buy the ticket
Print -1 if customer can't buy ticket

Sol1: For each customer's max price find the price > maxPrice (upperbound) Then consider previous one. Once ticket is assigned remove it 

Sol2: For each customer's max price find the price <= maxPrice (lowerbound) Then consider that price. Once ticket is assigned remove it


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
    int n,m;
    cin>>n>>m;

    vector<int> maxCustomerPrices(m), pricePaidAns(m);

    multiset<int> ticketPrices;

    for(int i=0;i<n;i++){
        int x; cin>>x;
        ticketPrices.insert(x);    
    }

    for(int i=0;i<m;i++) cin>>maxCustomerPrices[i];

    for(int i=0;i<m;i++)
    {
        if(ticketPrices.size() > 0)
        {
            auto it = ticketPrices.upper_bound(maxCustomerPrices[i]);
            it--;

            if(it == ticketPrices.end()){
                pricePaidAns[i] = -1;
            }else{
                //check again if the value returned is greater or not to ensure its correct before assigning ans
                if(*it > maxCustomerPrices[i]){
                    pricePaidAns[i] = -1;
                }else{
                    pricePaidAns[i] = *it;
                    ticketPrices.erase(it);
                }
            }
        }else{
            pricePaidAns[i] = -1;
        }
    }

    for(int i=0;i<m;i++) 
        DEBUG(pricePaidAns[i]); 
    
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
