class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> indegree(N+1,0),outdegree(N+1,0);
        for(int i=0;i<trust.size();i++){
            int a=trust[i][0],b=trust[i][1];
            outdegree[a]++;indegree[b]++;
        }
        vector<int> ans;
        ans.clear();
        for(int i=1;i<=N;i++){
            if(indegree[i]==N-1&&outdegree[i]==0) ans.push_back(i);
        }
        if(ans.size()==1) return ans[0];
        else return -1;
    }
};
