class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            int j=i+1,k=nums.size()-1;
            if(j>=nums.size()||j>=k) break;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0) --k;
                else if(sum<0) ++j;
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    --k;++j;
                    while(j<k&&nums[j]==nums[j-1]) ++j;
                    while(j<k&&nums[k]==nums[k+1]) --k;
                }
            }
        }
        return ans;

    }
};
