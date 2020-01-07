class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long long>> mp;
        mp.resize(m);
        for(int i = 0; i < m; i++)
            mp[i].resize(n);
        for(int i = 0; i < m; i++) {
            if(obstacleGrid[i][0] == 1) break;
            mp[i][0] = 1;
        }
        for(int i = 0; i < n; i++) {
            if(obstacleGrid[0][i] == 1) break;
            mp[0][i] = 1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1) mp[i][j]=0;
                else mp[i][j]=mp[i-1][j]+mp[i][j-1];
            }
        }
        return mp[m-1][n-1];
    }
};
