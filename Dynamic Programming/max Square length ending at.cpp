#include<bits/stdc++.h>
using namespace std;

 int maximalSquare(vector<vector<int>>& matrix) {
        
        int n=matrix.size(); 
        int m=matrix[0].size();
        
        //maximum square length ending at i,j including cell at (i,j)
        int dp[n+1][m+1];
        memset(dp,0, sizeof(dp));
        
        int len=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){ 
                    if(i==0 || j==0) 
                        dp[i][j]=1;
                    else 
                        dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                }
                
                len = max(len,dp[i][j]);
            }
        }
        
        return len*len;
    }

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<maximalSquare(arr)<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
