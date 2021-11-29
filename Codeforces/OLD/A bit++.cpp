#include<iostream>
using namespace std;

int main()
{

    int t,x=0;
    cin>>t;
    string s[t];

    for(int i=0;i<t;i++)
    {
        cin>>s[i];
    }

    for(int i=0;i<t;i++)
    {
        if(((s[i][0]=='X') && (s[i][2]=='+')) ||((s[i][2]=='X') && (s[i][0]=='+')) )
        {
            x+=1;
        }

        if(((s[i][0]=='X') && (s[i][2]=='-')) ||((s[i][2]=='X') && (s[i][0]=='-')) )
        {
            x-=1;
        }

        //cout<<s[i][0]<<endl;
    }

    cout<<x;
    return 0;
}
