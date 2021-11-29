#include<iostream>
#include<algorithm>

using namespace std;


int main()
{
    string s[2];
    int res;
    for(int i=0;i<2;i++)
    {
        cin>>s[i];
    }
    int i=0;
    transform(s[0].begin(), s[0].end(), s[0].begin(), ::tolower);
    transform(s[1].begin(), s[1].end(), s[1].begin(), ::tolower);
        for(int j=0;j<s[i].size();j++)
        {
            if((int)s[i][j]==(int)s[i+1][j])
            {
                res=0;
            }
            else
            {
            if((int)s[i][j]<(int)s[i+1][j])
            {
                res=-1;
                break;
            }
            else
            {
                res=1;
                break;
            }
            }

        }
        cout<<res;

    return 0;
}
