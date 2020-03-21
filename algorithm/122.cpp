class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int ans=0,last=prices[0];
        for(int i=1;i<prices.size();++i){
            if(prices[i]>last)
                ans+=(prices[i]-last);
            last=prices[i];
        }
        return ans;
    }
};
