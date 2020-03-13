class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len=nums.size(),last=nums[0],cnt=1;
        for(int i=1;i<len;++i){
            if(nums[i]==last) cnt++;
            else cnt--;
            if(cnt==0) last=nums[i+1];
        }
        return last;
    }
};
