/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node * cloneGraph(Node * node) {
        if (node == nullptr) {
            return node;
        }
        unordered_map<Node *, Node *> vis;

        queue<Node *> q;
        q.push(node);

        vis[node] = new Node(node->val);

        while (!q.empty()) {
            auto n = q.front();
            q.pop();

            for (auto & neighbor : n->neighbors) {
                if (vis.find(neighbor) == vis.end()) {
                    vis[neighbor] = new Node(neighbor->val);

                    q.push(neighbor);
                }
                vis[n]->neighbors.push_back(vis[neighbor]);
            }
        }

        return vis[node];
    }
};
// @lc code=end
