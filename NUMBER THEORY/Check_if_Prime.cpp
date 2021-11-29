#include<bits/stdc++.h>
#define ll long long
using namespace std;


//Naive Approach Loop through 2..n-1 ---O(n)
bool isPrime(ll n)
{
    if(n==1) return false;
    for(int i = 2; i<n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}


//Loop through 2...sqrt(n) ---O(sqrt(n))
bool isPrime(ll n)
{
    if(n==1) return false;
    for(int i=2; i*i<=n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}


//By eliminating multiples of 2,3,5,7---O(sqrt(n))
bool isPrime(ll n)
{
    if(n==1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;

    for(int i=5;i*i<=n;i=i+6)
    {
        if(n%i==0 || n%(i+2)==0)
            return false;
    }
    return true;
}


int main()
{
    ill n;
    cin>>n;
    if(isPrime(n))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
