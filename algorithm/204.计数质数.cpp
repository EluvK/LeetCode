/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
using namespace std;
class Solution {
public:
#define ll long long
    ll i, j, m;
    ll f[340000], g[340000], num;
    void init() {
        for (m = 1; m * m <= num; ++m)
            f[m] = num / m - 1;
        for (i = 1; i <= m; ++i)
            g[i] = i - 1;
        for (i = 2; i <= m; ++i) {
            if (g[i] == g[i - 1])
                continue;
            for (j = 1; j <= min(m - 1, num / i / i); ++j) {
                if (i * j < m)
                    f[j] -= f[i * j] - g[i - 1];
                else
                    f[j] -= g[num / i / j] - g[i - 1];
            }
            for (j = m; j >= i * i; --j)
                g[j] -= g[j / i] - g[i - 1];
        }
    }
    int countPrimes(int n) {
        num = n - 1;
        init();
        return f[1];
    }
};
// @lc code=end
