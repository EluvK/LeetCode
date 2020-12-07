/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 */

// @lc code=start
class Solution {
public:
    string Manacher(string s) {
        string t = "$#";
        for (auto c : s) {
            t += c;
            t += "#";
        }
        vector<int> p(t.size(), 0);
        int mx = 0, c = 0, resL = 0, resC = 0, ans = 0;
        for (int i = 1; i < t.size(); i++) {
            p[i] = mx > i ? min(p[2 * c - i], mx - i) : 1;
            while (t[i + p[i]] == t[i - p[i]])
                p[i]++;
            if (mx < i + p[i]) {
                c = i;
                mx = i + p[i];
            }
            if (resL < p[i]) {
                resL = p[i];
                resC = i;
            }
            if (resL == resC && resL - 1 > ans)
                ans = resL - 1;
        }
        return s.substr(0, ans);
    }
    string shortestPalindrome(string s) {
        std::cout << Manacher(s) << std::endl;
        string r = s.substr(Manacher(s).size());
        reverse(r.begin(), r.end());
        return r + s;
    }
};
// @lc code=end
