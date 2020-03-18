class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        for(int i=0;i<matrix.size();++i){
            int rowmin=INT_MAX,rowi=-1;
            for(int j=0;j<matrix[i].size();++j){
                if(matrix[i][j]<rowmin){
                    rowmin=matrix[i][j];
                    rowi=j;
                }
            }
            if(rowi==-1) continue;
            bool flag=true;
            for(int k=0;k<matrix.size();++k){
                if(k!=i&&matrix[k][rowi]>rowmin){
                    flag=false;break;
                }
            }
            if(flag) ans.push_back(rowmin);
        }
        return ans;
    }
};
