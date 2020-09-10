/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
using namespace std;
class Solution {
public:
    struct TrieNode {
        bool is_word;
        string str;
        vector<TrieNode *> nxt;
        TrieNode() : is_word{false}, nxt{vector<TrieNode *>(26, nullptr)} {}
    };

    TrieNode * root;
    int n, m;
    vector<string> ans;
    vector<vector<char>> data;
    unordered_set<string> tmp;
    vector<vector<bool>> vis;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void add(string & word) {
        TrieNode * tmp = root;
        for (auto c : word) {
            if (tmp->nxt[c - 'a'] == nullptr)
                tmp->nxt[c - 'a'] = new TrieNode();
            tmp = tmp->nxt[c - 'a'];
        }
        tmp->is_word = true;
        tmp->str = word;
    }

    void dfs(int x, int y, TrieNode * cur) {
        if (cur->is_word) {
            if (!tmp.count(cur->str)) {
                ans.push_back(cur->str);
                tmp.insert(cur->str);
            }
        }
        for (int i = 0; i < 4; i++) {
            int xx = dx[i] + x, yy = dy[i] + y;
            if (xx < 0 || xx >= n || yy < 0 || yy >= m || vis[xx][yy])
                continue;
            if (cur->nxt[data[xx][yy] - 'a']) {
                vis[xx][yy] = true;
                dfs(xx, yy, cur->nxt[data[xx][yy] - 'a']);
                vis[xx][yy] = false;
            }
        }
    }

    vector<string> findWords(vector<vector<char>> & board, vector<string> & words) {
        root = new TrieNode();
        data = board;
        ans = vector<string>();
        for (auto w : words)
            add(w);
        n = board.size();
        if (n == 0)
            return {};
        m = board[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (root->nxt[board[i][j] - 'a']) {
                    vis[i][j] = true;
                    dfs(i, j, root->nxt[board[i][j] - 'a']);
                    vis[i][j] = false;
                }
            }
        }
        return ans;
    }
};

// @lc code=end
