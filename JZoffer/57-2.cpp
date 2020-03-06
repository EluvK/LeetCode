class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int l=1,r=2,sum=3;
        vector<vector<int>> ans;
        if(target<3) return ans;
        while(r<=target/2+1){
            if(sum<target){
                sum+=++r;
            }else if(sum>target){
                sum-=l++;
            }else{
                vector<int> tmp;
                for(int k=l;k<=r;++k) tmp.push_back(k);
                ans.push_back(tmp);
                sum-=l++;
                sum+=++r;
            }
        }
        return ans;
    }
};
