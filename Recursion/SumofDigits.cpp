#include<iostream>
using namespace std;

int SumofDigits(int n)
{
    if(n<=9)
        return n;

    return n%10 + SumofDigits(n/10);
}

int main()
{

    /****************************STDIN/STDOUT******************************/
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    /****************************STDIN/STDOUT******************************/

    int n;
    cin>>n;

    cout<<SumofDigits(n)<<endl;

    return 0;
}
