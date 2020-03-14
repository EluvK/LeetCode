class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        queue<pair<int,int>> q;
        int m=grid.size();
        if(!m) return 0;
        int n=grid[0].size();
        if(!n) return 0;
        int ans=0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]&&!vis[i][j]){
                    int res=0;
                    q.push(make_pair(i,j));
                    vis[i][j]=true;
                    while(!q.empty()){
                        pair<int,int> f=q.front();
                        q.pop();
                        res++;
                        int x=f.first,y=f.second;
                        for(int k=0;k<4;++k){
                            int nx=x+dx[k],ny=y+dy[k];
                            if(nx>=0&&ny>=0&&nx<m&&ny<n&&grid[nx][ny]&&!vis[nx][ny]){
                                q.push(make_pair(nx,ny));
                                vis[nx][ny]=true;
                            }
                        }
                    }
                    ans=max(ans,res);
                }
            }
        }
        return ans;
    }
};
