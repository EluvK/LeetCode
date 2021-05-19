/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0;
        int cnt[10] = {0};
        for (auto c : secret) {
            cnt[c - '0']++;
        }
        for (auto index = 0; index < guess.size(); ++index) {
            if (guess[index] == secret[index]) {
                A++;
                cnt[guess[index] - '0']--;
            }
        }
        for (auto index = 0; index < guess.size(); ++index) {
            if (guess[index] != secret[index] && cnt[guess[index] - '0']) {
                cnt[guess[index] - '0']--;
                B++;
            }
        }
        string res = std::to_string(A) + "A" + std::to_string(B) + "B";
        return res;
    }
};
// @lc code=end

