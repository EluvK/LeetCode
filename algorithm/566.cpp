class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m=nums.size();
        if(!m) return nums;
        int n=nums[0].size();
        if(!n) return nums;
        long long p=(long long)m*(long long)n;
        long long q=(long long)r*(long long)c;
        if(p!=q) return nums;
        vector<vector<int>> ans(r,vector<int>(c,0));
        for(long long i=0;i<q;++i){
            ans[i/c][i%c]=nums[i/n][i%n];
        }
        return ans;
    }
};
