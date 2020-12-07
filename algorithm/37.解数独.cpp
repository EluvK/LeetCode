/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    bool row[10][10] = {false}, col[10][10] = {false}, block[10][10] = {false};
    int blank = 0;
    bool ans = false;
    void solveSudoku(vector<vector<char>> & board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    int bi = i / 3 * 3 + j / 3;
                    row[i][num] = true;
                    col[j][num] = true;
                    block[bi][num] = true;
                } else {
                    blank++;
                }
            }
        }
        dfs(board, 0, 0);
    }
    void dfs(vector<vector<char>> & board, int i, int j) {
        if (!blank) {
            ans = true;
            return;
        }
        int nj = j + 1, ni = i;
        if (nj == 9) {
            nj = 0;
            ni++;
        }
        if (board[i][j] != '.')
            dfs(board, ni, nj);
        else {
            bool flag = false;
            int bi = i / 3 * 3 + j / 3;
            for (int k = 1; k <= 9; ++k) {
                if (row[i][k] || col[j][k] || block[bi][k])
                    continue;
                flag = true;
                board[i][j] = '0' + k;
                blank--;
                row[i][k] = true;
                col[j][k] = true;
                block[bi][k] = true;
                dfs(board, ni, nj);
                if (!ans) {
                    board[i][j] = '.';
                    blank++;
                    row[i][k] = false;
                    col[j][k] = false;
                    block[bi][k] = false;
                } else
                    return;
            }
        }
        return;
    }
};

// @lc code=end
