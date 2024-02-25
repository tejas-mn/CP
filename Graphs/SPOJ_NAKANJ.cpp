#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int INF = 1e9+10;

int vis[8][8];
int lev[8][8];

void reset(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            lev[i][j]=INF;
            vis[i][j]=0;
        }
    }
}

int getX(string s){
    return s[0] - 'a';
}

int getY(string s){
    return s[1] - '1';
}

bool isValid(int x , int y){
    return x>=0 && y>=0 && x<8 && y<8;
}

vector<pair<int,int>> movements = {
    {-1,2},{1,2},
    {-1,-2},{1,-2},
    {2,-1},{2,1},
    {-2,-1},{-2,1},
}

int bfs(string source  , string dest){
    int source_x = getX(source);
    int source_y = getY(source);

    int dest_x = getX(dest);
    int dest_y = getY(dest);

    queue<pair<int,int>> q;
    q.push({source_x , source_y});

    vis[source_x][source_y] = 1;
    lev[source_x][source_y] = 0;

    while(!q.empty()){
        pair<int,int> cur_v = q.front();
        q.pop();

        int x = cur_v.first , y = cur_v.second;

        for(auto movement: movements){
            int childx = movement.first + x;
            int childy = movement.second + y;

            if(!isValid(childx,  childy)) continue;
            if(!vis[childx][childy]){
                q.push({childx  ,childy});
                lev[childx][childy] = level[x][y]+1;
                vis[childx][childy] = 1;
            }
        }
        if(lev[destx][desty]!=INF) break;
    }

    return lev[destx][desty];
}


int main(){
    int t;
    cin>>t;

    while(t--){
        reset();
        string s1,s2;
        cin>>s1>>s2;
        cout<<bfs(s1,s2)<<endl;
    }

    return 0;
}
