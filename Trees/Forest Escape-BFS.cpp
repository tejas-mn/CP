////////////////////////
There is a forest represented by a grid of n rows and m columns. 
At t=0 sec some of the cells are fired. Every second the fire spreads to the four adjacent cells. 
A man is stuck in the forest. In&nbsp;<strong>1</strong>&nbsp;sec he can move by one cell to the right, left, up, or&nbsp;down. 
If he reaches the sides or the corners of the grid, he will save his life. Your task is to find out if there a path exists such that he can escape avoiding the fire.
The fired cell is marked as 'X', the initial position of the man is marked as 'M', and all the other cells are '.'
////////////////////////

class Solution{
public:
    bool escapeForest(int n,int m,vector<vector<char>> &grid){
        // Code here
        queue<pair<int,int>> q;
        vector<vector<int>> timeTakenToCatchFire(n, vector<int>(m,-1));
        
        bool noFire = true;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X'){
                    noFire=false;
                    q.push({i,j});
                    timeTakenToCatchFire[i][j]=0;
                }
            }
        }
        
        if(noFire) return true;
        
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        
        
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            
            int x=p.first;
            int y=p.second;
            
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                if(!(nx<0 || nx>=n || ny<0 || ny >=m) && timeTakenToCatchFire[nx][ny]==-1){
                    q.push({nx,ny});
                    timeTakenToCatchFire[nx][ny] = timeTakenToCatchFire[x][y]+1;
                }
            }    
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'M'){
                    timeTakenToCatchFire[i][j] = 0;
                    q.push({i, j});
                    break;
                }
            }
        }
        
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            
            int x=p.first;
            int y=p.second;
            
            if(x == 0 || x == n-1 || y == 0 || y == m-1) return true;
            
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                //time taken ot reach by man > time taken to catch fire
                if(!(nx<0 || nx>=n || ny<0 || ny >=m) && timeTakenToCatchFire[nx][ny] > timeTakenToCatchFire[x][y] + 1){
                    q.push({nx,ny});
                    timeTakenToCatchFire[nx][ny] = timeTakenToCatchFire[x][y]+1;
                }
            }    
        }
        
        return false;
    }
};
