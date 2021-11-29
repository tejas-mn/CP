// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    vector<string> graycode(int n)
    {
        //Base Case-1
        if (n <= 0)
            return {"0"};

        //Base Case-2
        if (n == 1)
        {
          return {"0","1"};
        }

        //Recursive case
        vector<string> preCompute = graycode(n-1);
        vector<string> ans;

        //First Append 0 to all strings in preCompute
        for(int i=0;i<preCompute.size();i++)
        {
          string s = preCompute[i];
          ans.push_back("0" + s);
        }

         // Then Append 1 to all strings in reverse order
        for(int i=preCompute.size()-1;i>=0;i--)
        {
           string s = preCompute[i];
           ans.push_back("1" + s);
        }

        return ans;
    }
};

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        Solution ob;
        vector<string> ans= ob.graycode(n);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";

        cout<<"\n";
    }
}
