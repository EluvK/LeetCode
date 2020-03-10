class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(!len) return 0;
        vector<int> mx(len,prices[len-1]);
        for(int i=len-2;i>=0;--i) mx[i]=max(mx[i+1],prices[i]);
        int ans=0;
        for(int i=0;i<len;++i) ans=max(ans,mx[i]-prices[i]);
        return ans;
    }
};
