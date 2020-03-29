class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m=grid.size(),n=grid[0].size();
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        int ans=0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(grid[i][j]==1&&vis[i][j]==false){
                    ans=1;
                    q.push(make_pair(i,j));
                    vis[i][j]=true;
                }
        if(q.size()==m*n) return -1;
        while(!q.empty()){
            pair<int,int> f=q.front();
            int x=f.first,y=f.second;
            q.pop();
            for(int k=0;k<4;++k){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx>=0&&ny>=0&&nx<m&&ny<n&&vis[nx][ny]==false){
                    vis[nx][ny]=true;
                    grid[nx][ny]=grid[x][y]+1;
                    q.push(make_pair(nx,ny));
                    ans=max(ans,grid[nx][ny]);
                }
            }
        }
        return ans-1;
    }
};
