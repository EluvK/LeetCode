/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
using namespace std;
class Trie {
public:
    struct node {
        char val;
        bool word;
        map<char, node *> nextList;
        node(char c) {
            val = c;
            word = false;
            nextList.clear();
        }
    };
    node * root;
    /** Initialize your data structure here. */
    Trie() { root = new node('@'); }

    /** Inserts a word into the trie. */
    void insert(string word) {
        if (!word.empty())
            insertWord(root, word, 0);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        node * tmp = root;
        for (auto c : word) {
            if (tmp->nextList.find(c) == tmp->nextList.end())
                return false;
            tmp = tmp->nextList[c];
        }
        return tmp->word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node * tmp = root;
        for (auto c : prefix) {
            if (tmp->nextList.find(c) == tmp->nextList.end())
                return false;
            tmp = tmp->nextList[c];
        }
        return true;
    }

private:
    void insertWord(node * _root, string const & word, int index) {
        if (word.size() == index) {
            _root->word = true;
            return;
        }
        if (_root->nextList.find(word[index]) == _root->nextList.end()) {
            node * tmp = new node(word[index]);
            _root->nextList.insert({word[index], tmp});
        }
        insertWord(_root->nextList.at(word[index]), word, index + 1);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
