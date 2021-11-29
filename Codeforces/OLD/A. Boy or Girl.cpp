#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{

    string s;
    cin>>s;

    int cnt=0;
    unordered_set<int> hashtable;

    for(char x :s)
    {
        //cout<<(int)x<<" "<<x<<endl;

        if (hashtable.find((int)x)!=hashtable.end())
        {
            //cout<<"found "<<x<<s.size()-cnt<<" times\n";
        }
        else
        {
            hashtable.insert((int)x);
            cnt+=1;
        }
    }
    //cout<<"count "<<cnt<<endl;

    if(cnt%2==0)
    {
        cout<<"CHAT WITH HER!"<<endl;
    }
    else
    {
        cout<<"IGNORE HIM!"<<endl;
    }
    return 0;

}
