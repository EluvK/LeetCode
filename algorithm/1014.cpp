class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int len = A.size(),mi = A[0],res = -1;
        for(int i = 1; i < len; i++) {
            res = max(res, mi + A[i] - i);
            mi =  max(mi, A[i] + i);
        }
        return res;
    }
};
