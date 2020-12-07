/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
class WordDictionary {
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
    WordDictionary() { root = new node('@'); }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        if (!word.empty())
            insertWord(root, word, 0);
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) { return searchWord(root, word, 0); }

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

    bool searchWord(node * _root, string const & word, int index) {
        if (index == word.size()) {
            return _root->word;
        }
        if (word[index] != '.') {
            if (_root->nextList.find(word[index]) == _root->nextList.end()) {
                return false;
            } else {
                return searchWord(_root->nextList[word[index]], word, index + 1);
            }
        } else {
            bool flag = false;
            for (auto pr : _root->nextList) {
                flag |= searchWord(pr.second, word, index + 1);
                if (flag)
                    return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
