class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int len=nums.size();
        for(int i=0;i<len;i++){
            while(nums[i]!=i){
                if(nums[i]==nums[nums[i]]) return nums[i];
                swap(nums[i],nums[nums[i]]);
            }
        }
        return -1;
    }
};
