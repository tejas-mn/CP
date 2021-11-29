#include<bits/stdc++.h>
#define ll long long
using namespace std;

//Optimized Sieve----O(n*log(log(n)))
void Sieve(ll n)
{
    vector<bool> isPrime(n+1,true);
    cout<<2<<endl;
    for(ll i=3;i<=n;i+=2)
    {
        if(isPrime[i])
        {
            cout<<i<<endl;
            for(ll j=i*i ;j<=n;j=j+i)      //Normal sieve-->j=2*i
                isPrime[j]=false;
        }
    }
}

//By eliminating multiples of 2,3,5,7
bool isPrime(ll n)
{
    if(n==1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;

    for(ll i=5;i*i<=n;i=i+6)
    {
        if(n%i==0 || n%(i+2)==0)
            return false;
    }
    return true;
}

//Naive Approach
void printPrimes(ll n)
{
    for(ll i=2;i<=n;i++)
    {
        if(isPrime(i))
            cout<<i<<endl;
    }
}

int main()
{
    ll n;
    cin>>n;
    printPrimes(n);
    Sieve(n);
    return 0;
}
