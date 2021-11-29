
    /*****************************HEADERS***********************************/

    #include<bits/stdc++.h>

    /****************************#DEFINE************************************/

    #define ll              long long
    #define ull             unsigned long long
    #define endl            "\n"
    #define cout(x)         cout<<x<<endl
    #define cin(x)          cin>>x
    #define cinn(x,y)       cin>>x>>y
    #define coutt(x,y)      cout<<x<<" "<<y
    #define vi              vector<int>
    #define vinput(x)       for(int &e:x){cin(e);}
    #define voutput(x)      for(int e:x){cout<<e<<" ";} cout<<endl;
    #define pb              push_back
    #define all(v)          v.begin(),v.end()
    #define sort(v)         sort(all(v))
    #define reverse(v)      reverse(all(v))
    #define acc(v,s)        accumulate(all(v),s)
    #define count(v,n)      count(all(v), n)
    #define FOR(i,n)        for(i=0;i<n;i++)
    #define minv(v)         *min_element(all(v))
    #define maxv(v)         *max_element(all(v))
    #define FAST_IO         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    using namespace std;

    /**************************CONSTANTS***********************************/

    const int inf           =1e9 + 10;
    const unsigned int M    =1000000007;
    const int mod           =1e9+7;
    const int INF           =0x3f3f3f3f;
    const ll llINF          =9223372036854775807;
    const int N             =1e5+10;
    const double pi         =acos(-1.0);

    /***************************COMMON FUNCTIONS***************************/

    ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
    ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
    bool iseven(int n) {return (n%2==0)?true:false;}

    /*****************************SOLVE HERE*******************************/

    solve()
    {
        ll n;
        cin(n);
        vi v(n);
        vinput(v);

        //using two pointer
        int low=0;
        int high=n-1;

        //element to consider and turn is initially sereja
        int consider;
        char turn='s';

        //initially sereja and dema score is 0
        int s=0,d=0;

        //while elements are not exhausted
        while(low<=high)
        {
            //If left most is greater than right most consider the left and move the left pointer
            //else consider the right most and move right pointer
            if(v[low]>v[high])
            {
                consider=v[low];
                low++;
            }
            else
            {
                consider=v[high];
                high--;
            }

            //If turn is sereja's then sum up the considered elements and change turn to dima
            if(turn=='s')
            {
                s=s+consider;
                turn='d';
            }
            else
            {
                d=d+consider;
                turn='s';
            }
        }
        coutt(s,d);
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
        //cin>>t;
        while(t-->0)
        {
            solve();
        }
        return 0;
    }

    /*********************************NOTE************************************/

    /*Two pointer approach

    sorted or unsorted array
    low=0 high n-1
    while(low<=high)
    {
        if(condition)
        {
            low++;
        }
        else
        {
            high--;
        }

        other conditions
    }
    cout or return

    */

    /*********************************NOTE************************************/
