#include<bits/stdc++.h>
using namespace std;


class Solution{
	public:
	    vector<string> v;

	    void generate_subsets(string s , string curr="" , int i=0)
	    {

	        // if i has reached end
	        if(i==s.size())
	        {
	            if(curr!= "") v.push_back(curr);
	            return;
	        }

	        //dont include ith char in curr string
	        generate_subsets(s, curr , i+1);

	        //include ith char in curr string
	        generate_subsets(s, curr+s[i] , i+1);

	    }

		vector<string> AllPossibleStrings(string s){

		    generate_subsets(s);

		    sort(v.begin() , v.end());

		    return v;
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

	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
