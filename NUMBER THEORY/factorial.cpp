#include<bits/stdc++.h>
using namespace std;

//Iterative
int factorial(int n)
{
    int fact=1;

    for(int i=2;i<=n;i++)
        fact=fact*i;

    return fact;
}

//Recursive
int factorial(int n)
{
    if(n<=1)
        return 1;
    else
        return n*factorial(n-1);
}


int main()
{
    int n;
    cin>>n;
    cout<<factorial(n);
    return 0;
}
