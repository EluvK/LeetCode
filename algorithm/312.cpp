class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int> > dp=vector<vector<int> >(n+2,vector<int>(n+2,0));

        nums.insert(nums.begin(),1);
        nums.push_back(1);

        for(int len=1;len<=n;++len){
            //i<=n-len(n-1)+1
            for(int i=1;i<=n-len+1;++i){
                int j=i+len-1;
                for(int k=i;k<=j;++k){
                    dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+nums[k]*nums[i-1]*nums[j+1]);
                }
            }
        }
        return dp[1][n];
    }
};
