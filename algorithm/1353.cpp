bool cmp(vector<int>& a,vector<int>& b){
    return a[1]!=b[1]?a[1]>b[1]:a[0]<b[0];
}
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),cmp);
        reverse(events.begin(),events.end());
        // for(int i=0;i<events.size();++i){
        //     cout<<events[i][0]<<" "<<events[i][1]<<endl;
        // }
        bool vis[100005]={false};
        int ans=0;
        for(int i=0;i<events.size();++i){
            for(int j=events[i][0];j<=events[i][1];++j){
                if(!vis[j]){
                    ans++;vis[j]=true;break;
                }
            }
        }
        return ans;
    }
};
