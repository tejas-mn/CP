#include<bits/stdc++.h>
using namespace std;
#define ll long long

//Naive Approach - Calculate factorial and while last digit is 0 increment count --this method overflows for n>20
ll countTrailingZeroes(ll n)
{
    ll fact=1;
    for(ll i=2;i<=n;i++)
        fact=fact*i;

    ll count=0;
    while(fact%10==0)
    {
        ++count;
        fact = fact/10;
    }
    return count;
}

//Efficient Method --0 is contributed by 2 and 5 but number of 2s<5s so calculate
//n/5 + n/25 + n/125... upto where multiples of 5<=n
ll countTrailingZeroes(ll n)
{
    ll count=0;
    for(ll i=5;i<=n;i=i*5)
        count=count+(n/i);
    return count;
}

int main()
{
    ll n;
    cin>>n;
    cout<<countTrailingZeroes(n);
    return 0;
}
