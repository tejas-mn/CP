#include<bits/stdc++.h>
using namespace std;


//Naive Approach----O(n)
int power(int x,int n)
{
    int res=1;
    for(int i=0;i<n;i++)
        res=res*x;
    return res;
}


//Recursive Modular Arithmetic to compute (x^n)%M
//O(logn) time and space
int power_mod(int x,int n,int m)
{
    if(n==0) return 1;

    if(n%2==0)
    {
        int y = power_mod(x,n/2,m);
        return (y*y)%m;
    }
    else
        return ((x%m)*power_mod(x,n-1,m))%m;
}


//Binary Exponentiation
//O(logn)
int power(int x , int n)
{
    int res=1;
    while(n>0)
    {
        if(n%2!=0) res=res*x;
        x=x*x;
        n=n/2;
    }
    return res;
}


//Binary Exponentiation With BitWise operators and ,modulo
//O(logn)
int power_mod(int x , int n , int m)
{
    int res=1;
    while(n)
    {
        if(n&1) res=(res*x)%m;
        x=(x*x)%m;
        n=n>>1;
    }
    return res;
}

int main()
{
    int x,n,m;
    cin>>x>>n>>m;
    cout<<power_mod(x,n,m);
    return 0;
}
