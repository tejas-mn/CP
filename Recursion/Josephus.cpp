#include<bits/stdc++.h>
using namespace std;

int josephus(int n, int k)
{
    //base case - If there is only one person
    if(n==1)
        return 0;
    else
    //each time a person is killed n reduces by 1
    //every positions get increased by k so +k
    //treat every starting positions as killing so %n
    return (josephus(n-1 , k) + k)%n;


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
    int k;
    cin>>k;

    cout<<josephus( n,  k) + 1<<endl;

    return 0;
}
