/*
Find the number of binary strings of length n where “0100” is not present as a substring.
*/

#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int maxN = 1000010;
int dp[1000010][5];

int rec(int idx, int prefMatchLength){
    //pruning 
    if(prefMatchLength==4){ //0100 is present as a substring
        return 0;
    }

    //base case - u have found string where 0100 not present as substr
    if(idx==0) return 1;
    
    //cache check
    if(dp[idx][prefMatchLength]!=-1) return dp[idx][prefMatchLength];
    
    //compute
    int ans = 0;
    
    if(prefMatchLength == 0){
        //"" : take 0 => 1 length match in 0100 + take 1 => 0 length match 
        ans = rec(idx-1, 1)%mod + rec(idx-1, 0)%mod;
    }else if(prefMatchLength == 1){
        //"0" : take 0 => 00 (still 1 length match with 0100) + take 1 => 01 (2 length match)
        ans = rec(idx-1, 1)%mod + rec(idx-1, 2)%mod;
    }else if(prefMatchLength == 2){
        //"01" : take 0 => 010 (3 length match) + take 1 => 011 (0 length match - cant consider pref 01 as a match and skip the 3rd one since this is substring problem)
        ans = rec(idx-1, 3)%mod + rec(idx-1, 0)%mod;
    }else if(prefMatchLength == 3){
        //"010" : take 0 => 0100 (all 4 length match) + take 1 => 0101 (only suff 01 in 0101 matches as substring without any break -> 2 length match)
        ans = rec(idx-1, 4)%mod + rec(idx-1, 2)%mod;
    }
    
    return dp[idx][prefMatchLength] = ans%mod;
}

void solve(){
	int n;
    cin>>n;
    cout<<rec(n, 0)%mod<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for writing output to output.txt
  freopen("output.txt", "w", stdout);
  #endif

	//memoize for max N across all test cases to reduce overall TC
	memset(dp, -1, sizeof(dp));

  int t; cin>>t;
  while(t--) solve();
  return 0;
}
