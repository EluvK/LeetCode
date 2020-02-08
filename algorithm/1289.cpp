class Solution {
public:
    int getmin(vector<int> v,int j){
        int ans=INT_MAX;
        for(int i=0;i<v.size();i++){
            if(i!=j&&v[i]<ans) ans=v[i];
        }
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& arr) {
        vector<vector<int>> dp=arr;
        int m=arr.size(),n=arr[0].size();
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=arr[i][j]+getmin(dp[i-1],j);
            }
        }
        return *min_element(dp.back().begin(),dp.back().end());
    }
};
