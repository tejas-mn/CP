#include<bits/stdc++.h>
#define ll long long
using namespace std;


//Iterative
int CountDigit(ll n)
{
    int cnt=0;
    int sum=0;
    int digit;

    while(n!=0)
    {
        digit=n%10;
        sum=sum+digit;

        n=n/10;
        ++cnt;
    }

    return cnt;
}

//Recursive
int CountDigit(ll n)
{
        if(n==0)
            return 0;
        else
            return 1 + CountDigit(n/10);
}

//Using Log Base 10--O(1)
int CountDigit(ll n)
{
    return floor(log10(n)+1);
}

//Converting number to string
int CountDigit(ll n)
{
    return to_string(n).size();
}


int main()
{
    ll n;
    cin>>n;
    cout<<CountDigit(n)<<endl;
    return 0;
}
