#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll Reverse(ll n)
{
    ll rev=0;
    while(n!=0)
    {
        int digit = n%10;
        rev = digit + (rev*10);
        n=n/10;
    }
    return rev;
}

ll Reverse(ll n)
{
    string s = to_string(n);
    reverse(s.begin(),s.end());
    return stoi(s);
}


ll Reverse(ll n)
{
    static int rev=0;
    static int base=1;

    if(n>0)
    {
        Reverse(n/10);
        rev = rev + (n%10)*base;
        base=base*10;
    }
    return rev;
}


bool IsPalindrome(ll n)
{
    if(Reverse(n)==n)
        return true;
    else
        return false;
}

int main()
{

    ll n;
    cin>>n;

    if(IsPalindrome(n))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
