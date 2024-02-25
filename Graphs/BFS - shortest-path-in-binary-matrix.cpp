class Solution {
private:
    int moves[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
public:

    bool isValid(int i,int j , vector<vector<int>> &grid){
        int n = grid.size();
        if(i>=0 && j>=0 && j<n && i<n && grid[i][j]==0) return true;
        return false;
    }

    int bfs(vector<vector<int>> &grid){
        int n = grid.size();
        queue<pair<int,int>> q;

        int level[n][n];
        memset(level , 0 , sizeof level);

        //1 bcoz level/distance in terms of no. of cells traversed
        level[0][0] = 1;

        //push source
        q.push({0,0});

        //mark source as visited
        grid[0][0] = 1;


        while(!q.empty())
        {
            pair<int,int> cur_v = q.front();
            q.pop();

            //return level/Shortest distance of destination(n-1,n-1)
            if(cur_v.first == n-1 && cur_v.second==n-1) return level[cur_v.first][cur_v.second];

            for(auto p : moves){
                int dx = cur_v.first + p[0];
                int dy = cur_v.second + p[1];

                if(isValid(dx,dy,grid)){
                    q.push({dx,dy});
                    grid[dx][dy] = 1;
                    level[dx][dy] = level[cur_v.first][cur_v.second] + 1;
                }
            }

        }
        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
        int n = grid.size();

        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        return bfs(grid);
    }
};
