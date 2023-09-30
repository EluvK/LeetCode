/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache {
private:
    int m_cap;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> l;

public:
    LRUCache(int capacity) : m_cap(capacity) {}

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            int val = mp[key]->second;
            l.erase(mp[key]);
            l.push_front(make_pair(key, val));
            mp[key] = l.begin();
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            l.erase(mp[key]);
            l.push_front(make_pair(key, value));
            mp[key] = l.begin();
        } else {
            if (l.size() == m_cap) {
                mp.erase(l.back().first);
                l.pop_back();
            }
            l.push_front(make_pair(key, value));
            mp[key] = l.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
