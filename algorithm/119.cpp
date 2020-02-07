class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1,1);
        long cur=1;
        for(int i=0;i<rowIndex;i++){
            cur=cur*(rowIndex-i)/(i+1);
            ans[i+1]=(int)cur;
        }
        return ans;
    }
};
