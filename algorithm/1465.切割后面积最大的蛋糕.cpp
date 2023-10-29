/*
 * @lc app=leetcode.cn id=1465 lang=cpp
 *
 * [1465] 切割后面积最大的蛋糕
 */

// @lc code=start
class Solution {
public:
    int maxArea(int h, int w, vector<int> & horizontalCuts, vector<int> & verticalCuts) {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int mh = horizontalCuts[0];
        int mw = verticalCuts[0];
        for (int i = 1; i < horizontalCuts.size(); ++i) {
            mh = max(mh, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for (int i = 1; i < verticalCuts.size(); ++i) {
            mw = max(mw, verticalCuts[i] - verticalCuts[i - 1]);
        }
        return (int)(((long long)mh * mw) % (long long)(1e9 + 7));
    }
};
// @lc code=end
