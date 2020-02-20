class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        bool vis[110]={false};
        int group[110]={0};
        queue<int> q;
        for(int i=0;i<graph.size();++i){
            if(vis[i]) continue;
            q.push(i);
            vis[i]=true;
            group[i]=1;
            while(!q.empty()){
                int f=q.front();
                q.pop();
                for(auto c:graph[f]){
                    if(vis[c]&&group[f]*group[c]==1) return false;
                    if(!vis[c]){
                        vis[c]=true;
                        group[c]=group[f]*(-1);
                        q.push(c);
                    }
                }
            }
        }
        return true;

    }
};
