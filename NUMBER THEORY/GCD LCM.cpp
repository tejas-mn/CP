#include<bits/stdc++.h>
using namespace std;


//Naive -> GCD(a,b) <= min(a,b)
//O(min(a,b))
int gcd(int a,int b)
{
    int res = min(a,b);

    while(res>0)
    {
        if(a%res==0 && b%res==0)
            break;
        res--;
    }

    return res;
}

//Naive-LCM(a,b)>=Max(a,b)
//O(a*b-Max(a,b))
int lcm(int a,int b)
{
        int res = max(a,b);

        while(true)
        {
            if(res%a==0 && res%b==0)
                return res;
            res++;
        }

        return res;
}


//GCD(a,b)=GCD(a-b,b) if b<a
//O(log(min(a,b)))
int gcd(int a,int b)
{
    while(a!=b)
    {
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    return a;
}

//Euclidian GCD - O(log(min(a,b)))
int gcd(int a , int b)
{
    if(b==0)
        return a;
    else return gcd(b,a%b);
}

//LCM - O(log(min(a,b)))
int lcm(int a,int b)
{
    return (a*b)/gcd(a,b);
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<" "<<lcm(a,b)<<endl;
    return 0;
}
