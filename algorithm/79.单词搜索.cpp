/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
using namespace std;
class Solution {
public:
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    bool dfs(vector<vector<char>> & board, string const & word, int index, int i, int j, vector<vector<bool>> & vis) {
        if (index == word.size()) {
            return true;
        }
        if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || word[index] != board[i][j]) {
            return false;
        }
        if (!vis[i][j]) {
            vis[i][j] = true;
            for (int k = 0; k < 4; ++k) {
                if (dfs(board, word, index + 1, i + dx[k], j + dy[k], vis))
                    return true;
            }
            vis[i][j] = false;
        }
        return false;
    }

    bool exist(vector<vector<char>> & board, string word) {
        if (!board.size() || !board[0].size()) {
            if (word.size()) {
                return false;
            }
            return true;
        }
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (dfs(board, word, 0, i, j, vis))
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end
