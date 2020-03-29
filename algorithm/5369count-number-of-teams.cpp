class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        vector<int> cnt1(n,0),cnt2(n,0),cnt3(n,0),cnt4(n,0);
        for(int i=1;i<n-1;++i){
            for(int j=0;j<i;++j){
                if(rating[j]<rating[i]) cnt1[i]++;
                else cnt2[i]++;
            }
        }
        for(int i=n-2;i>0;--i){
            for(int j=n-1;j>i;--j){
                if(rating[j]<rating[i]) cnt3[i]++;
                else cnt4[i]++;
            }
        }
        int ans=0;
        for(int i=1;i<n-1;++i){
            ans+=(cnt1[i]*cnt4[i]+cnt2[i]*cnt3[i]);
        }
        return ans;

    }
};
