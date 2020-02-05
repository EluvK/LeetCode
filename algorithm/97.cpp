class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1=s1.size(),len2=s2.size(),len3=s3.size();
        if(len1+len2!=len3) return false;
        vector<vector<bool>> dp(len1+2,vector<bool>(len2+2,false));
        //dp[i][j] means i in s1 & j in s2 == i+j in s3
        dp[0][0]=true;
        if(s3[0]==s1[0]) dp[1][0]=true;
        if(s3[0]==s2[0]) dp[0][1]=true;
        for(int i=0;i<=len1;++i){
            for(int j=0;j<=len2;++j){
                // if(dp[i][j]==false) break;//can not do this.
                if(dp[i][j]&&s3[i+j]==s1[i]) dp[i+1][j]=true;
                if(dp[i][j]&&s3[i+j]==s2[j]) dp[i][j+1]=true;
            }
        }
        return dp[len1][len2];
    }
};
