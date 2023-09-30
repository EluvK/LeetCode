/*
 * @lc app=leetcode.cn id=2844 lang=cpp
 *
 * [2844] 生成特殊数字的最少操作
 */

// @lc code=start
class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        int minOps = n;
        if (n == 1) {
            if (num == "0")
                return 0;
            return 1;
        }
        if (n == 2) {
            if (atoi(num.c_str()) % 25 == 0)
                return 0;
            if (num[1] == '0')
                return 1;
            return 2;
        }

        num = "0" + num;
        for (int i = n; i >= 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                char ci = num[i];
                char cj = num[j];
                if ((100 + ci - '0' + (cj - '0') * 10) % 25 == 0) {
                    cout << n << " " << i << " " << j << endl;
                    int ops = n - 1 - j - 2;
                    minOps = min(minOps, ops);
                }
            }
        }

        return minOps;
    }
};
// @lc code=end
