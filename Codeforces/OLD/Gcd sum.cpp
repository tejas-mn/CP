#include<iostream>
#include<vector>
#include<cmath>
using namespace std ;


long long int gcd(long long int a, long long int b)
{
    if(a==0)
    {
        return b;
    }
    else{return gcd(b%a,a);}
}

//or
/*
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);

}*/


long long int sumofdigits(long long int x)
{
    long long int sum=0;
    long long int rem;
    while(x>0)
    {
        rem=x%10;
        sum=sum+rem;
        x=floor(x/10);
    }
    return sum;
}

long long int gcdSum(long long int n)
{
    return gcd(n,sumofdigits(n));
}

void solve()
{
    long long n;
    cin>>n;
    while(gcdSum(n)<=1)
    {
        n++;
    }
    cout<<n<<"\n";

}


int main()
{

    long int t;
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}
