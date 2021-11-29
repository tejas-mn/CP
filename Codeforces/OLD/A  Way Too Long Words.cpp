#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int t=n;
    string word[t];
    while(n--)
    {
        cin>>word[n];
    }
    while(t--)
    {
        if(word[t].size()>10)
        {
            cout<<word[t][0]<<word[t].size()-2<<word[t][word[t].size()-1]<<endl;
        }
        else
        {
            cout<<word[t]<<endl;
        }
    }

    return 0;
}
