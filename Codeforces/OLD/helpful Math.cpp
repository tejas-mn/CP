#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main()
{
    string s,res="";
    vector<int> arr;

    //cin.get(s,100);
    cin>>s;
    //int len=strlen(s);

    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='+')
        {
            //-'0' to extract digits from strings into integer
            arr.push_back((int)s[i]-'0');
        }
    }

    sort(arr.begin(),arr.end());

    for(int x:arr)
    {
        //+'0' to extract digits from integer to string
        res.push_back(x+'0');
        res.push_back('+');

    }
    //to pop last added '+'
    res.pop_back();

    cout<<res;

    return 0;
}
