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
    int n;
    cin>>n;
    string s;
    cin>>s;

    int ans = INT_MAX;


    //for each char in alpahabets
    for(char c = 'a';c<='z';c++)
    {
        int cnt=0;

        //two pointers
        int low=0;
        int high = n-1;

        while(low<high)
        {
            //if first and last char is EQ proceed..
            if(s[low]==s[high]){
                low++;high--;
            }

            //if not equal
            else if(s[low]!=s[high]){

                //s[low] should be removed
                if(s[low]==c){
                    low++;
                    cnt++;
                }else

                //s[high] should be removed
                if(s[high]==c){
                    high--;
                    cnt++;
                }

                //differnt char other than c..make cnt max and break bcoz not possible to remove
                else
                {
                    cnt=INT_MAX;
                    break;
                }

            }
        }

        //For each char calculate min cnt (GREEDY APPROACH)
        ans = min(ans , cnt);
    }

    if(ans!=INT_MAX) cout<<ans<<endl;
    else cout<<-1<<endl;
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
