#include<bits/stdc++.h>
using namespace std;


class Solution {
private:

public:
    bool isValid(int i , int j  , vector<vector<char>>&grid)
    {
        int n=grid.size();
        int m=grid[0].size();

        if((i>=0 and j>=0 and i<n and j<m ) && (grid[i][j]=='.')) return true;
        return false;

    }

    void dfs(int i , int j  , vector<vector<char>>&grid)
    {
        if(isValid(i,j,grid))
        {
            //instead of maintaining vis array do this
            grid[i][j]='#';
             cout<<i<<" "<<j<<endl;
            dfs(i+1,j,grid);

            dfs(i-1, j,grid);

            dfs(i,j+1,grid);

            dfs(i,j-1,grid);

        }

    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='#') continue;

                dfs(i,j,grid);
                cnt++;
            }
        }

        return cnt;
    }
};

int main(){

    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);

    Solution s;
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v;
    for(int i=0;i<n;i++){
        vector<char> temp;
        for(int j=0;j<m;j++){
             char x;cin>>x;
             temp.push_back(x);
        }
        v.push_back(temp);
    }

    int ans = s.numIslands(v);
    cout<<ans<<endl;

    return 0;
}
