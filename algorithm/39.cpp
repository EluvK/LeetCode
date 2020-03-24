class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(vector<int> &v,int i,int sum,int target){
        if(sum==target) ans.push_back(temp);
        for(int j=i;j<v.size();++j){
            if(sum+v[j]>target) break;
            temp.push_back(v[j]);
            dfs(v,j,sum+v[j],target);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        temp.clear();
        sort(candidates.begin(),candidates.end());
        dfs(candidates,0,0,target);
        return ans;
    }
};
