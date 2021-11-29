#include<bits/stdc++.h>
#define ll long long
using namespace std;


//Naive Approach
void printDivisors(ll n)
{
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
            cout<<i<<endl;
    }
}


//Efficient but not sorted--O(sqrt(n))
void printDivisors(ll n)
{
    //Loop from 1 to sqrt(n)
    for(int i=1;i*i<=n;i++)
    {
        //If i divides n
        if(n%i==0)
        {
            //print i
            cout<<i<<endl;

            //to eliminate printing divisors twice(Eg: if n=25 then 25/5 == 5 which is prime but 5 already printed so..)
            if(i!=n/i)
                cout<<(n/i)<<endl;
        }
    }
}


//Efficient AND sorted--O(sqrt(n))
void printDivisors(ll n)
{
    int i;

    //print all divisors(i if n%i==0) from 1...sqrt(n) [exclusive]
    for(i=1;i*i<=n;i++)
    {
        if(n%i==0)
            cout<<i<<endl;
    }

    //print all divisors (n/i if n%i==0) from sqrt(n) to n
    for(;i>=1;i--)
    {
        if(n%i==0)
            cout<<n/i<<endl;
    }
}


int main()
{
    ll n;
    cin>>n;
    printDivisors(n);
    return 0;
}
