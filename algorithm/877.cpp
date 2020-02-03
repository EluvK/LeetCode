#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int len=piles.size();
        vector<vector<int>> dp(len,vector<int>(len,0));
        for(int i=0;i<len;i++) dp[i][i]=piles[i];

        for(int i=1;i<len;i++){
            for(int j=0;j<len-i;j++){
                dp[j][i+j]=max((piles[j]-dp[j+1][i+j]),(piles[i+j]-dp[j][i+j-1]));
            }
        }
        return dp[0][len-1]>0;

    }
};

int main(){
    vector<int> v={5,3,4,5};
    Solution s;
    s.stoneGame(v);
    return 0;
}
