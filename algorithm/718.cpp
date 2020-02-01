class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int> > dp(A.size(),vector<int>(B.size(),0));
        int ans=0;
        for(int i=0;i<A.size();i++){
            dp[0][i]=A[0]==B[i]?1:0;
            if(dp[0][i]>ans) ans=dp[0][i];
        }
        for(int i=0;i<B.size();i++){
            dp[i][0]=A[i]==B[0]?1:0;
            if(dp[i][0]>ans) ans=dp[i][0];
        }
        for(int i=1;i<A.size();i++){
            for(int j=1;j<B.size();j++){
                if(A[i]==B[j]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    if(dp[i][j]>ans) ans=dp[i][j];
                }
                else dp[i][j]=0;
            }
        }
        return ans;
    }
};
