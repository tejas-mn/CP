#include<bits/stdc++.h>
#define ll long long
using namespace std;


//Naive Approach---O(n2logn)
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

void printPrimeFactors(ll n)
{
    //Loop from 2..n
    for(int i=2;i<=n;i++)
    {
        //If i is Prime
        if(isPrime(i))
        {
            //Take i as x
            int x=i;

            //While x Divides n
            while(n%x==0)
            {
                //Print i and multiply x with i
                cout<<i<<endl;
                x=x*i;
            }
        }
    }
}


//Loop through 2 ...sqrt(n)
void printPrimeFactors(ll n)
{
    if(n<=1) return ;

    for(ll i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            cout<<i<<endl;
            n=n/i;
        }
    }

    if(n>1)
        cout<<n<<endl;
}


//Checking primilarity with 2,3,5,7--O(sqrt(n))
void printPrimeFactors(ll n)
{
    if(n<=1) return;

    while(n%2==0)
    { {
        cout<<3<<endl;
        n=n/3;
    }

    for(ll i=5;i*i<=n;i+=6)
    {
        while(n%i==0)
        {
            cout<<i<<en
            n=n/i;
        }

        while(n%(i+2)==0)
        {
            cout<<(i+2)<<endl;
            n=n/(i+2);
        }
    }

    if(n>3)
        cout<<n<<endl;

}

int main()
{
    printPrimeFactors