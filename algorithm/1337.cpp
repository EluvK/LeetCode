class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>> v;
        int len=mat[0].size();
        v.clear();
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<len;j++){
                if(mat[i][j]==0){
                    v.push_back({j,i});
                    break;
                }
            }
            if(mat[i][len-1]==1){
                v.push_back({len,i});
            }
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        ans.clear();
        for(int i=0;i<k;i++)
            ans.push_back(v[i][1]);
        return ans;
    }
};
