class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(len<2) return 0;
        vector<int> dp1(len,0),dp2(len,0);
        int mn=prices[0],mx=prices[len-1];
        for(int i=1;i<len;++i){
            dp1[i]=max(dp1[i-1],prices[i]-mn);
            mn=min(prices[i],mn);
        }
        for(int i=len-2;i>=0;--i){
            dp2[i]=max(dp2[i+1],mx-prices[i]);
            mx=max(prices[i],mx);
        }
        int ans=0;
        for(int i=0;i<len;++i) ans=max(ans,dp1[i]+dp2[i]);
        return ans;
    }
};
