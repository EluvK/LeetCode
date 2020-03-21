class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt[3000]={0};
        for(int i=0;i<arr2.size();++i){
            cnt[arr2[i]-d+1500]++;
            cnt[arr2[i]+d+1501]--;
        }
        for(int i=1;i<3000;++i) cnt[i]=cnt[i]+cnt[i-1];
        int ans=0;
        for(int i=0;i<arr1.size();++i){
            if(cnt[arr1[i]+1500]==0){
                ans++;
                // cout<<arr1[i]<<endl;
            }
        }
        // cout<<endl;
        return ans;
    }
};
