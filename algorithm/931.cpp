class Solution {
public:
    int Tmin(int a,int b,int c){
        if(a>b) return b>c?c:b;
        else return a>c?c:a;
    }
    int minFallingPathSum(vector<vector<int>>& A) {
        int m=A.size(),n=A[0].size();
        vector<vector<int>> dp=A;
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    dp[i][j]=A[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
                }else if(j==n-1){
                    dp[i][j]=A[i][j]+min(dp[i-1][j-1],dp[i-1][j]);
                }else{
                    dp[i][j]=A[i][j]+Tmin(dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]);
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(dp[n-1][i]<ans) ans=dp[n-1][i];
        }
        return ans;
    }
};
