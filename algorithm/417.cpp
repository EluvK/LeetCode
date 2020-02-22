class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(!m) return matrix;
        int n=matrix[0].size();
        if(!n) return matrix;
        int dx[4]={1,0,-1,0};
        int dy[4]={0,-1,0,1};
        vector<vector<bool>> vis1(m,vector<bool>(n,false)),vis2(m,vector<bool>(n,false));
        vector<vector<int>> ans;
        queue<pair<int,int>> q;
        for(int i=0;i<m;++i){
            pair<int,int> p=make_pair(i,0);
            q.push(p);
            vis1[i][0]=true;
        }
        for(int i=1;i<n;++i){
            pair<int,int> p=make_pair(0,i);
            q.push(p);
            vis1[0][i]=true;
        }
        while(!q.empty()){
            pair<int,int> f=q.front();
            q.pop();
            for(int i=0;i<4;++i){
                int x=f.first+dx[i],y=f.second+dy[i];
                if(x>=0&&x<m&&y>=0&&y<n){
                    if(!vis1[x][y]&&matrix[x][y]>=matrix[f.first][f.second]){
                        q.push(make_pair(x,y));
                        vis1[x][y]=true;
                    }
                }
            }
        }
        for(int i=0;i<m;++i){
            pair<int,int> p=make_pair(i,n-1);
            q.push(p);
            vis2[i][n-1]=true;
        }
        for(int i=0;i<n-1;++i){
            pair<int,int> p=make_pair(m-1,i);
            q.push(p);
            vis2[m-1][i]=true;
        }
        while(!q.empty()){
            pair<int,int> f=q.front();
            q.pop();
            if(vis1[f.first][f.second]&&vis2[f.first][f.second]){
                ans.push_back({f.first,f.second});
            }
            for(int i=0;i<4;++i){
                int x=f.first+dx[i],y=f.second+dy[i];
                if(x>=0&&x<m&&y>=0&&y<n){
                    if(!vis2[x][y]&&matrix[x][y]>=matrix[f.first][f.second]){
                        q.push(make_pair(x,y));
                        vis2[x][y]=true;
                    }
                }
            }
        }
        return ans;
    }
};
