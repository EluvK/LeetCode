struct node{
    int x,h;
    node(int _x,int _h){x=_x;h=_h;}
    bool operator <(const node& other) const{
        return h>other.h;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<3) return 0;
        priority_queue<node> q;
        q.push(node{0,height[0]});
        q.push(node{n-1,height[n-1]});
        vector<bool> vis(n,false);
        vis[0]=vis[n-1]=true;
        int dx[2]={1,-1};
        int ans=0;
        while(!q.empty()){
            node p=q.top();
            q.pop();
            for(int i=0;i<2;++i){
                int x=p.x+dx[i];
                if(x<0||x>=n) continue;
                if(!vis[x]){
                    if(height[x]>=p.h){
                        q.push(node{x,height[x]});
                        vis[x]=true;
                    }else{
                        ans+=p.h-height[x];
                        q.push(node{x,p.h});
                        vis[x]=true;
                    }
                }
            }
        }
        return ans;
    }
};
