class Solution {
public:
    int findLucky(vector<int>& arr) {
        int len=arr.size();
        int cnt[510]={0};
        for(int i=0;i<len;++i){
            cnt[arr[i]]++;
        }
        int ans=-1;
        for(int i=1;i<501;++i){
            if(cnt[i]==i) ans=i;
        }
        return ans;
    }
};
