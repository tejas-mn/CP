#include<iostream>
#include<cmath>
#define ll long long

using namespace std;
const unsigned int M = 1000000007;

unsigned  f(unsigned ll i,ll int f1,ll int f2)
{
    if(i==1)
        return f1;
    if(i==2)
        return f2;

    return (f(i-1,f1,f2)%M - f(i-2,f1,f2)%M);
}

int main()
{
    ll int  f1,f2;
    unsigned ll n;
    unsigned  res;
    cin>>f1>>f2;
    cin>>n;

    unsigned ll r;

    //Pattern repeats for every six values
    //f1,f2,f3,f4,f5,f6,f1,f2,f3...
    for(r=6;r>0;r--){

     res=f(r,f1,f2);

     if(n%6==0 && r==6)
     {
        cout<<((res+M)%M)<<"\n";
        break;
     }

    if (r==n%6)
    {
        cout<<((res+M)%M)<<"\n";
        break;
    }

    }

    return 0;
}
