#include<iostream>
#include<vector>

using namespace std;

void solve()
{
    long long int n;
    int res;
    cin>>n;
    while (n)
    {
        res=n;
        n=n&(n - 1);
    }
    cout<<res-1<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    long long int t;
    //t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }


    return 0;
}
