class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int cnt[110]={0};
        for(auto c:nums) cnt[c]++;
        int res[110]={0};
        for(int i=1;i<110;++i) res[i]+=res[i-1]+cnt[i-1];
        vector<int> ans(nums.size(),0);
        for(int i=0;i<ans.size();++i) ans[i]=res[nums[i]];
        return ans;
    }
};
