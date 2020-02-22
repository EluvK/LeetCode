class Solution {
public:
    int countOrders(int n) {
        int mod=1000000007;
        long long ans=1;
        for(int i=n*2;i>0;i=i-2){
            ans=ans*((i*(i-1))/2);
            ans=ans%mod;
        }
        return (int)ans;
    }
};
