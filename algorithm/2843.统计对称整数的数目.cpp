/*
 * @lc app=leetcode.cn id=2843 lang=cpp
 *
 * [2843] 统计对称整数的数目
 */

// @lc code=start
class Solution {
public:
    bool isSymmetricNumber(int num) {
        string num_str = to_string(num);
        if (num_str.size() % 2)
            return false;
        int n = num_str.length() / 2;
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            sum1 += num_str[i] - '0';
            sum2 += num_str[i + n] - '0';
        }
        return sum1 == sum2;
    }
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int num = low; num <= high; num++) {
            if (isSymmetricNumber(num)) {
                count++;
            }
        }
        return count;
    }
};
// @lc code=end
