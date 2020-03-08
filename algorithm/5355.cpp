class Solution {
public:
    vector<double> pos;
    vector<bool> vis;
    vector<vector<int>> d;
    vector<vector<int>> rd;
    void dfs(int st,int from,int ct,int mt){
        if(ct==mt){
            vis[st]=true;
            return;
        }
        int cnt=d[st].size()+rd[st].size();
        if(st!=1) cnt--;
        bool flag=false;
        for(int i=0;i<d[st].size();++i){
            int nxt=d[st][i];
            if(nxt!=from){
                pos[nxt]=pos[st]/(double)cnt;
                dfs(nxt,st,ct+1,mt);
                flag=true;
            }
        }
        for(int i=0;i<rd[st].size();++i){
            int nxt=rd[st][i];
            if(nxt!=from){
                pos[nxt]=pos[st]/(double)cnt;
                dfs(nxt,st,ct+1,mt);
                flag=true;
            }
        }
        if(!flag) vis[st]=true;
        return;
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        pos.resize(n+1);
        d.resize(n+1);
        rd.resize(n+1);
        vis.resize(n+1);
        pos[1]=1.0;
        fill(vis.begin(),vis.end(),false);
        for(int i=0;i<edges.size();++i){
            int x=edges[i][0],y=edges[i][1];
            d[x].push_back(y);
            rd[y].push_back(x);
        }
        dfs(1,-1,0,t);
        long long sum=0;

        if(vis[target]) return pos[target];
        else return 0;
    }
};
