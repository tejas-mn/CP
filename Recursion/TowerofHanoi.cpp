#include<bits/stdc++.h>
using namespace std;

void tower(int n , char S , char T , char D)
{
    //base case - if there is one disc
    if(n==1)
    {
        cout<<"Move disc "<<n<<" from "<<S<<" to "<<D<<endl;
        return;
    }

    tower(n-1 , S , D ,T);
    cout<<"Move disc "<<n<<" from "<<S<<" to "<<D<<endl;
    tower(n-1 , T ,S, D);

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
/******************************WRITE HERE*********************************/

    int n;
    cin>>n;

    tower(n , 's' , 't' , 'd');
    cout<<"Total moves : "<<pow(2,n)-1<<endl;
    return 0;
}
