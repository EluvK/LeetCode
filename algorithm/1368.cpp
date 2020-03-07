class Solution {
public:
    const int dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0};
    int d[105][105];
    deque<pair<int,int>> q;
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        memset(d,127,sizeof(d));
        d[0][0]=0;
        q.clear();
        q.push_back(make_pair(0,0));
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop_front();
            for(int i=1;i<5;++i){
                if(x+dx[i]>=0&&x+dx[i]<m&&y+dy[i]>=0&&y+dy[i]<n){
                    if(i==grid[x][y]&&d[x+dx[i]][y+dy[i]]>d[x][y]){
                        d[x+dx[i]][y+dy[i]]=d[x][y];
                        q.push_front(make_pair(x+dx[i],y+dy[i]));
                    }else if(i!=grid[x][y]&&d[x+dx[i]][y+dy[i]]>d[x][y]+1){
                        d[x+dx[i]][y+dy[i]]=d[x][y]+1;
                        q.push_back(make_pair(x+dx[i],y+dy[i]));
                    }
                }
            }
        }
        return d[m-1][n-1];
    }
};
