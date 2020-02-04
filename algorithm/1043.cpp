#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int len=A.size(),mx=0;
        if(len==0) return 0;
        vector<int> dp(len+1,0);
        dp[1]=A[0];
        for(int i=2;i<=len;i++){
            mx=A[i-1];
            for(int j=i;j>=max(1,i-K+1);j--){
                mx=max(mx,A[j-1]);
                dp[i]=max(dp[i],dp[j-1]+mx*(i-j+1));
            }
        }
        return dp[len];
    }
};

int main(){
    vector<int> v={1,15,7,9,2,5,10};
    Solution s;
    cout<<s.maxSumAfterPartitioning(v,3);
    return 0;
}
