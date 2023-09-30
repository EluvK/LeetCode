/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

// @lc code=start
class LFUCache {
private:
    struct Node {
        int key;
        int value;
        int freq;
        Node(int _k, int _v, int _f) : key{_k}, value{_v}, freq{_f} {}
    };
    std::unordered_map<int, std::list<Node>> freq_table;  // every freq's Node list
    std::unordered_map<int, std::list<Node>::iterator> key_table;

    int m_capacity;
    int m_min_freq;

public:
    explicit LFUCache(int capacity) {
        freq_table.clear();
        key_table.clear();
        m_capacity = capacity;
        m_min_freq = 0;
    }

    int get(int key) {
        if (m_capacity == 0) {
            return -1;
        }
        auto iter = key_table.find(key);
        if (iter == key_table.end()) {
            return -1;
        }
        auto node = iter->second;
        int freq = node->freq;
        int value = node->value;

        freq_table[freq].erase(node);
        if (freq_table[freq].size() == 0) {
            freq_table.erase(freq);
            if (m_min_freq == freq) {
                m_min_freq += 1;
            }
        }
        freq_table[freq + 1].push_front(Node(key, value, freq + 1));
        key_table[key] = freq_table[freq + 1].begin();
        return value;
    }

    void put(int key, int value) {
        if (m_capacity == 0) {
            return;
        }
        auto iter = key_table.find(key);
        if (iter == key_table.end()) {
            if (key_table.size() == m_capacity) {
                auto erase_iter = freq_table[m_min_freq].back();
                key_table.erase(erase_iter.key);
                freq_table[m_min_freq].pop_back();
                if (freq_table[m_min_freq].size() == 0) {
                    freq_table.erase(m_min_freq);
                }
            }
            freq_table[1].push_front(Node{key, value, 1});
            key_table[key] = freq_table[1].begin();
            m_min_freq = 1;
        } else {
            auto node = iter->second;
            int freq = node->freq;
            freq_table[freq].erase(node);
            if (freq_table[freq].size() == 0) {
                freq_table.erase(freq);
                if (m_min_freq == freq) {
                    m_min_freq += 1;
                }
            }
            freq_table[freq + 1].push_front(Node(key, value, freq + 1));
            key_table[key] = freq_table[freq + 1].begin();
        }
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
