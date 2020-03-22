class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int l[7]={0,1,0,1,0,1,0};
        int r[7]={0,1,0,0,1,0,1};
        int u[7]={0,0,1,0,0,1,1};
        int d[7]={0,0,1,1,1,0,0};
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        vis[0][0]=true;
        while(!q.empty()){
            pair<int,int> f=q.front();
            q.pop();
            int x=f.first,y=f.second;
            if(x==m-1&&y==n-1) return true;
            int dir=grid[x][y];
            if(l[dir]&&y-1>=0&&vis[x][y-1]==false&&r[grid[x][y-1]]){
                q.push(make_pair(x,y-1));
                vis[x][y-1]=true;
            }
            if(r[dir]&&y+1<n&&vis[x][y+1]==false&&l[grid[x][y+1]]){
                q.push(make_pair(x,y+1));
                vis[x][y+1]=true;
            }
            if(u[dir]&&x-1>=0&&vis[x-1][y]==false&&d[grid[x-1][y]]){
                q.push(make_pair(x-1,y));
                vis[x-1][y]=true;
            }
            if(d[dir]&&x+1<m&&vis[x+1][y]==false&&u[grid[x+1][y]]){
                q.push(make_pair(x+1,y));
                vis[x+1][y]=true;
            }
        }
        return false;
    }
};
