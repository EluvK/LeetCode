/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int P = max(A, E), Q = max(B, F), X = min(C, G), Y = min(D, H);
        int area = (C - A) * (D - B);
        if (X > P && Y > Q)
            area -= (X - P) * (Y - Q);
        return area + (G - E) * (H - F);
    }
};
// @lc code=end
