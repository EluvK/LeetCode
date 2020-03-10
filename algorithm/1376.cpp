class Solution {
public:
    vector<int> cnt;
    vector<vector<int>> d;
    vector<int> t;
    void dfs(int id){
        for(int i=0;i<d[id].size();++i){
            cnt[d[id][i]]=cnt[id]+t[id];
            dfs(d[id][i]);
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        cnt.resize(n);
        fill(cnt.begin(),cnt.end(),0);
        d.resize(n);
        t=informTime;
        for(int i=0;i<manager.size();++i){
            if(manager[i]!=-1) d[manager[i]].push_back(i);
        }
        dfs(headID);

        return *max_element(cnt.begin(),cnt.end());
    }
};
