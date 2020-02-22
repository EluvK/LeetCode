#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node{
    int x,y,h;
    node(int _x,int _y,int _h){x=_x;y=_y;h=_h;}
    bool operator < (const node &other) const{
        return h>other.h;
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        if(m<3) return 0;
        int n=heightMap[0].size();
        if(n<3) return 0;
        priority_queue<node> q;
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;++i) q.push(node{i,0,heightMap[i][0]}),vis[i][0]=true;
        for(int i=1;i<n;++i) q.push(node{m-1,i,heightMap[m-1][i]}),vis[m-1][i]=true;
        for(int i=1;i<n;++i) q.push(node{0,i,heightMap[0][i]}),vis[0][i]=true;
        for(int i=1;i<m-1;++i) q.push(node{i,n-1,heightMap[i][n-1]}),vis[i][n-1]=true;
        int cnt=1;
        while(!q.empty()){
            node f=q.top();
            q.pop();
            // cout<<cnt++<<":"<<"("<<f.x<<","<<f.y<<")"<<f.h<<endl;
            for(int i=0;i<4;++i){
                int x=f.x+dx[i],y=f.y+dy[i];
                if(x<0||y<0||x>=m||y>=n) continue;
                if(!vis[x][y]){
                    // cout<<"  to:"<<x<<","<<y<<endl;
                    if(heightMap[x][y]>=f.h){
                        q.push(node{x,y,heightMap[x][y]});
                        vis[x][y]=true;
                    }else{
                        ans+=f.h-heightMap[x][y];
                        // cout<<"ans:"<<ans<<endl;
                        q.push(node{x,y,f.h});
                        vis[x][y]=true;
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> v={{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    Solution s;
    cout<<s.trapRainWater(v);
    return 0;

}
