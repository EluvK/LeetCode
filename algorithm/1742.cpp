inline bool cmp(vector<int> &a,vector<int> &b){
    if(a[0]!=b[0]) return a[0]>b[0];
    else return a[1]<b[1];
}
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int cnt[100010]={0};
        vector<vector<int>> v;
        v.clear();
        for(auto c:arr) cnt[c]++;
        for(int i=0;i<100010;i++){
            if(cnt[i]!=0){
                v.push_back({cnt[i],i});
            }
        }
        sort(v.begin(),v.end(),cmp);
        int len=arr.size()/2;
        int ans=0;
        while(len>0){
            len-=v[ans++][0];
        }
        return ans;
    }
};
