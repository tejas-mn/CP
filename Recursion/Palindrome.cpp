#include<bits/stdc++.h>
using namespace std;


bool isPalindrome(string s , int low , int high)
{
    if(low<=high)
    {

        if(s[low] ==  s[high])
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    return isPalindrome( s  , low+1 , high-1);
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

    string s;
    cin>>s;

    if(isPalindrome(s , 0 , s.size()-1)){
        cout<<"Yes"<<endl;
    }else{
    cout<<"No";
    }

    return 0;
}
