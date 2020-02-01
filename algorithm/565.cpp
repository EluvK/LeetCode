class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int len,ans=0,nxt,temp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==-1) continue;
            len=1;
            nxt=nums[i];
            nums[i]=-1;
            while(nxt!=i){
                ++len;
                temp=nums[nxt];
                nums[nxt]=-1;
                nxt=temp;
            }
            ans=max(ans,len);
        }
        return ans;
    }
};
