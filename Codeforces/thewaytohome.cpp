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
    int n,d;
    cin>>n>>d;

    string str;
    cin>>str;

    int i=d,pos=0,cnt=0;

    while(i>0 && i<=n-1){

        if(i==n-1 && str[i]=='1'){
            cout<<cnt+1<<endl;
            return ;
        }

        if(str[i]=='1'){
            pos=i;
            cnt+=1;
            i+=d;
        }
        else{
            i--;
            if(i==pos){
                cout<<-1<<endl;
                return;
            }

        }

    }

    if(cnt==0){
        cout<<-1<<endl;
    }
    else{
        cout<<cnt+1<<endl;
    }

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
    t=1;
    while(t-->0){
        solve();
    }
    return 0;
}
