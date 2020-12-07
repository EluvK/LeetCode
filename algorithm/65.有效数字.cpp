/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */

// @lc code=start
class Solution {
public:
    vector<bool> finals{false, false, false, true, false, true, true, false, true};
    vector<vector<int>> transfer{{0, 1, 6, 2, -1, -1},
                                 {-1, -1, 6, 2, -1, -1},
                                 {-1, -1, 3, -1, -1, -1},
                                 {8, -1, 3, -1, 4, -1},
                                 {-1, 7, 5, -1, -1, -1},
                                 {8, -1, 5, -1, -1, -1},
                                 {8, -1, 6, 3, 4, -1},
                                 {-1, -1, 5, -1, -1, -1},
                                 {8, -1, -1, -1, -1, -1}};

    int char2state(char c) {
        switch (c) {
        case ' ':
            return 0;
        case '+':
        case '-':
            return 1;
        case '.':
            return 3;
        case 'e':
            return 4;
        default:
            if (isdigit(c))
                return 2;
            else
                return 5;
        }
    }

    bool isNumber(string s) {
        int state = 0;
        for (auto c : s) {
            state = transfer[state][char2state(c)];
            if (state < 0)
                return false;
        }
        return finals[state];
    }
};
// @lc code=end
