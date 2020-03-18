class Solution {
public:
    int arrangeCoins(int n) {
        return range(n,1);
    }
    int range(int n,int s){
        if(n<s) return 0;
        else return 1+range(n-s,s+1);
    }
};
