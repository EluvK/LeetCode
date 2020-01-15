#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len=nums.size();
        if(len<2) return nums;
        int resi=0,resl=1;
        vector<int> dp(len,1),pre(len,-1);
        sort(nums.begin(),nums.end());
        for(int i=1;i<len;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        pre[i]=j;
                    }
                }
            }
            if(dp[i]>resl){
                resl=dp[i];
                resi=i;
            }
        }
        vector<int> res;
        while(resi!=-1){
            res.push_back(nums[resi]);
            resi=pre[resi];
        }
        return res;

    }
};

int main(){
    vector<int> v={1,2,4,6,8,16,32,14,62,99};
    Solution s;
    vector<int> res=s.largestDivisibleSubset(v);
    for(auto c:res) cout<<c<<" ";
    return 0;
}
