/*
Given a string S. The task is to print all permutations of a given string.
https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1#
*/

#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	    vector<string> ans ;

	    //i=0 :  fix first character
	    void permute_helper(string s,  int i=0 )
	    {
	        //base case - if i has reached end
	        if(i==s.size())
	        {

                //push the resultant permutation
	            ans.push_back(s);
	            return;
	        }

	        //for characters in range of j = i ..n-1
	        for(int j=i;j<s.size();j++)
            {
                //swap s[i] and s[j]
                swap(s[i] , s[j]);

                //find permutations for next char
                permute_helper(s , i+1);

                //swap s[i] and s[j] once again for next set of permutations
                swap(s[i] , s[j]);
	        }

	    }

		vector<string>find_permutation(string S)
		{

		    permute_helper(S);

		    //sort the vector to get permutations in lexicographic order
		    sort(ans.begin() , ans.end());

		    return ans;
		}
};



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

    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
