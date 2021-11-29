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
    int a,b,p,q;
    cin>>a>>b>>p>>q;


    int m[10][10];
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            if(((i+j)%2)==0){
                m[i][j]=1;//white
            }else{
            m[i][j]=0;//black
            }
        }
    }



    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }

    if((a&b&p&q)) {
        cout<<0<<endl;
        return;
    }


            if(m[a][b]!=m[p][q]){
                cout<<1<<endl;
            }
            else if(m[a][b]==m[p][q]){
                cout<<2<<endl;
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
    cin>>t;

    while(t-->0){
        solve();
    }
    return 0;
}
