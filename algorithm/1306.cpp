class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int len=arr.size();
        vector<bool> vis(len,false);
        queue<int> q;
        q.push(start);
        vis[start]=true;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            if(f+arr[f]<len&&f+arr[f]>=0&&vis[f+arr[f]]==false){
                q.push(f+arr[f]);vis[f+arr[f]]=true;
            }
            if(f-arr[f]<len&&f-arr[f]>=0&&vis[f-arr[f]]==false){
                q.push(f-arr[f]);vis[f-arr[f]]=true;
            }
        }
        for(int i=0;i<len;i++){
            if(arr[i]==0&&vis[i]) return true;
        }
        return false;
    }
};
